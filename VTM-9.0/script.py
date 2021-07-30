from os import system, path

import time
from threading import Thread


def main():
        cmd = 'rm -R features; rm -R target; mkdir features; mkdir target; ./make.sh'
        system(cmd)

        #videos = [
        #        'Lips', 'SunBath', 'Netflix_Dancers',
        #        'BuildingHall', 'ToddlerFountain', 'Touchdown_pass',
        #        'Jockey_1080p', 'Beauty_1080p', 'RushFieldCuts', 'Netflix_TunnelFlag',
        #        'Vidyo4', 'Dark', 'NetflixDinnerScene', 'KristenAndSara', 'Netflix_DrivingPOV'
        #]

        videos = ['Vidyo4', 'Dark', 'NetflixDinnerScene', 'KristenAndSara', 'Netflix_DrivingPOV']

        videos.reverse()

        MAX_THREADS = 5  # numero maximo de threads que executarao
        INI_THREADS = 1
        threads = []     # lista de threads
        for i in range (MAX_THREADS):
                video = videos.pop(0)
                print ('Starting ' + video + ' Core ' + str(i + INI_THREADS))
                threads.append(Th(i + INI_THREADS, video))
                threads[i].start()

        while(True):
                dead_threads = 0
                for i, thread in enumerate(threads):
                        video = None
                        if not thread.isAlive():
                                try:
                                        video = videos.pop(0)
                                except:
                                        dead_threads += 1
                                if video != None:
                                        print('Starting ' + video)
                                        threads[i] = Th(i + INI_THREADS, video)
                                        threads[i].start()

                if dead_threads == MAX_THREADS:
                        return
                time.sleep(60)



class Th(Thread):
        def __init__ (self, core, video):
                Thread.__init__(self)
                self.core   = str(core)
                self.video  = video

        def run(self):
                qps = ['22','27','32','37']
                #qps = ['22']

                video_path = {
                        'Lips':                   ['/home/matheuslin/videos/Lips_3840x2160_120fps_10bit.yuv', 8],
                        'SunBath':                ['/home/matheuslin/videos/SunBath_3840x2160_50fps_10bit.yuv', 8],
                        'Netflix_Dancers':        ['/home/matheuslin/videos/NetflixDancers_4096x2160_60fps_10bit_420_60f.yuv', 8],
                        'BuildingHall':           ['/data/videos/4k_jvet/BuildingHall2_3840x2160_50fps_10bit_420.yuv', 8],
                        'ToddlerFountain':        ['/data/videos/4k_jvet/ToddlerFountain_4096x2160_60fps_10bit_420_jvet.yuv', 8],
                        
                        'Touchdown_pass':         ['/home/matheuslin/videos/TouchdownPass_1080p_60f.yuv', 16],
                        'Jockey_1080p':           ['/data/videos/1080p_UVG/Jockey_1920x1080_120fps_420_8bit_YUV.yuv', 16],
                        'Beauty_1080p':           ['/home/matheuslin/videos/Beauty_1920x1080_120fps_420_8bit_YUV.yuv', 16],
                        'RushFieldCuts':          ['/home/matheuslin/videos/rush_field_cuts_1080p_60f.yuv', 16],
                        'Netflix_TunnelFlag':     ['/home/matheuslin/videos/NetflixTunnelFlag_1920x1080_60fps_8bit_420_60f.yuv', 16],
                        
                        'Vidyo4':                 ['/home/lindino/Documentos/rawVideos/Treinamento/Vidyo4_1280x720_60.yuv', 16],
                        'Dark':                   ['/home/lindino/Documentos/rawVideos/Treinamento/dark720p_120f.yuv', 16],
                        'NetflixDinnerScene':     ['/home/lindino/Documentos/rawVideos/Treinamento/Netflix_DinnerScene_1280x720_60fps_8bit_420_120f.yuv', 16],
                        'KristenAndSara':         ['/home/lindino/Documentos/rawVideos/Treinamento/KristenAndSara_1280x720_60.yuv', 16],
                        'Netflix_DrivingPOV':     ['/home/lindino/Documentos/rawVideos/Treinamento/NetflixDrivingPOV_1280x720_60fps_8bit_420_120f.yuv', 16],
                }

                #intraPeriod = {20:16, 24:32, 30:32, 50:48, 60:64, 100:96, 120:128}

                #in_peri = str(intraPeriod[video_path[self.video][0]])
                in_file = video_path[self.video][0]
                in_frames = str(video_path[self.video][1])
                encoderCfgFile = "encoder_randomaccess_vtm.cfg"


                for qp in qps:
                        outFile = "out_VTM/" + self.video + "_" + qp + ".txt"
                        bsFile = "video_bin/str_" + self.video + "_" + qp + ".bin"
                        cmd = "taskset -c " + self.core + " ./bin/EncoderAppStaticd -c cfg/" + encoderCfgFile + " -c cfg/per-sequence/" + self.video + ".cfg --QP=" + qp + \
                                        " --SIMD=SCALAR --VideoName=" + self.video + " --FramesToBeEncoded=" + in_frames + " --InputFile=" + in_file + " --BitstreamFile=" + bsFile + " > " + outFile
                        print (cmd)
                        system(cmd)


if __name__ == '__main__':
    main()