import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
from copy import deepcopy
from sklearn.feature_extraction import image


class YUVHandler:
    def __init__(self, yuv_path = None, w = 0, h = 0, sampling = '420'):
        self.yuv_path = yuv_path
        self.yuv_fp = None
        self.w = int(w)
        self.h = int(h)
        self.sampling = sampling
        self.frames_read = 0
        self.YUV = None
        self.yuv = None
        self.Y = self.U = self.V = None

        if self.yuv_path:
            self.yuv_fp = open(self.yuv_path, 'rb')




    def set_yuv_path(self, yuv_path):
        self.yuv_path = yuv_path
    def set_res(self, h, w):
        self.h, self.w = h, w
    def set_sampling(self, sampling):
        self.sampling = sampling

    def get_frame_arrays(self, max_frames = float('+inf')):
        if self.yuv_path:
            self.YUV = np.fromfile(self.yuv_path,dtype='uint8')
        else: return

        YUV, h, w = self.YUV, self.h, self.w
        subsample = 2 if self.sampling == '420' else 1

        px = w*h
        Y, U, V = [], [], []

        i = 0
        while (i < YUV.shape[0]) and self.frames_read != max_frames:

            luma_end = i+px
            cb_end = luma_end + (px//(subsample**2))
            cr_end = cb_end + (px//(subsample**2))

            Y.append(YUV[i:luma_end].reshape(h,w))
            U.append(YUV[luma_end:cb_end].reshape(h//subsample,w//subsample))
            V.append(YUV[cb_end:cr_end].reshape(h//subsample,w//subsample))


            i = cr_end
            self.frames_read += 1



        self.Y, self.U, self.V = np.asarray(Y), np.asarray(U), np.asarray(V)

        return self.Y, self.U, self.V

    def get_single_frame(self, index = -1):
        yuv, h, w = self.yuv, self.h, self.w
        subsample = 2 if self.sampling == '420' else 1
        px = w*h
        if index != -1:
            pt = index * w * h * 3 / subsample
            self.yuv_fp.seek(int(pt))

        frame_size = px + 2*(px//(subsample**2))

        if self.yuv_fp and frame_size:
            yuv = np.fromfile(self.yuv_fp,dtype='uint8', count = frame_size)
        else: return


        y, u, v = [], [], []

        luma_end = px
        cb_end = luma_end + (px//(subsample**2))
        cr_end = cb_end + (px//(subsample**2))

        y = yuv[:luma_end].reshape(h,w)
        u = yuv[luma_end:cb_end].reshape(h//subsample,w//subsample)
        v = yuv[cb_end:cr_end].reshape(h//subsample,w//subsample)


        self.y, self.u, self.v = np.asarray(y), np.asarray(u), np.asarray(v)
        return self.y, self.u, self.v

    def blockshaped(self, arr, nrows, ncols):
        """
        Return an array of shape (n, nrows, ncols) where
        n * nrows * ncols = arr.size

        If arr is a 2D array, the returned array should look like n subblocks with
        each subblock preserving the "physical" layout of arr.
        """
        h, w = arr.shape
        assert h % nrows == 0, "{} rows is not evenly divisble by {}".format(h, nrows)
        assert w % ncols == 0, "{} cols is not evenly divisble by {}".format(w, ncols)
        return (arr.reshape(h//nrows, nrows, -1, ncols)
                   .swapaxes(1,2)
                   .reshape(-1, nrows, ncols))

    def get_luma_CTUs(self, frame = None, tam = 64, index = 0):
        if frame is not None:
            y = deepcopy(frame)
        else:
            y = deepcopy(self.y)

        y = y[:self.h//tam*tam, :self.w//tam*tam]
        
        #y = image.extract_patches_2d(y, (tam,tam))
        
        y = self.blockshaped(y, tam, tam)

        self.plot_frame(y[index])

        return y


    def plot_frame(self, y, u = None, v = None, file_path = None):
        if u is not None and v is not None:
            yuv_rgb = self.to_RGB(y,u,v)
            plt.imshow(yuv_rgb)
        else:
            plt.imshow(y, cmap = 'gray')

        if file_path:
            plt.savefig(file_path)
        else:
            plt.show()

    def to_RGB(self,y,u,v):
        h,w = y.shape
        Ufull = np.repeat(u, 2,axis=0)
        Ufull = np.repeat(Ufull, 2,axis=1)
        Vfull = np.repeat(v, 2,axis=0)
        Vfull = np.repeat(Vfull, 2,axis=1)

        yuv_ycbcr = np.stack((y, Ufull, Vfull), axis = 2)

        return Image.fromarray(yuv_ycbcr, mode = 'YCbCr').convert('RGB')


    def get_sobel_frame(self, frame):
        sobelFrame = []
        clip = 1
        h,w = frame.shape
        sobelFrame = cv2.Sobel(frame,cv2.CV_64F,1,1,ksize=3)  

        return sobelFrame
    
    def get_SI(self, frame):
        sob = self.get_sobel_frame(frame)
        return sob.std()

    def get_TI(self, frame_i, frame_ii):
        return (frame_ii - frame_i).std()