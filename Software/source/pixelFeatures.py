import numpy as np
import pandas as pd
from scipy import ndimage

class pixelFeatures:
	def __init__(self, videoName, Y, width, height, POC):
		self.videoName = videoName
		self.Y = Y
		self.width = width
		self.height = height
		self.POC = POC

	def extractFeatures(self, CU_width, CU_height, split):
		df = pd.DataFrame(columns = ['topLeft_x', 'topLeft_y', 'bottomRight_x', 'bottomRight_y', 'POC', 'variance', 'mean', 'gradientH', 'gradientV', 'ratioGrad', 'sum',
                            'quarter1Var','quarter1Mean','quarter1GradH','quarter1GradV','quarter1RatioGrad','quarter1Sum','quarter2Var','quarter2Mean','quarter2GradH','quarter2GradV','quarter2RatioGrad','quarter2Sum',
                            'quarter3Var','quarter3Mean','quarter3GradH','quarter3GradV','quarter3RatioGrad','quarter3Sum','quarter4Var','quarter4Mean','quarter4GradH','quarter4GradV','quarter4RatioGrad','quarter4Sum'])
		index = 0

		for poc in range(self.POC):
			imageInput = self.Y[poc]
			for h in range(0, self.height, CU_height):
				for w in range(0, self.width, CU_width):
					xTL = w
					yTL = h
					xBR = w + CU_width  - 1
					yBR = h + CU_height - 1
					currentFeatures = self.calcFeatures(imageInput, xTL, yTL, xBR, yBR)

					if split == 'QT_SPLIT':
						quartersFeatures = self.quarterSplit(imageInput, int(CU_height/2), int(CU_width/2), xTL, yTL, xBR, yBR, split)					
					elif split == 'BI_HORZ':
						quartersFeatures = self.quarterSplit(imageInput, int(CU_height/2), int(CU_width), xTL, yTL, xBR, yBR, split)
					elif split == 'BI_VERT':
						quartersFeatures = self.quarterSplit(imageInput, int(CU_height), int(CU_width/2), xTL, yTL, xBR, yBR, split)
					elif split == 'TRI_HORZ':
						quartersFeatures = self.quarterSplit(imageInput, int(CU_height/4), int(CU_width), xTL, yTL, xBR, yBR, split)
					elif split == 'TRI_VERT':
						quartersFeatures = self.quarterSplit(imageInput, int(CU_height), int(CU_width/4), xTL, yTL, xBR, yBR, split)
					else:
						print('Invalid Split!')
						return

					self.writeDataFrame(df, index, split, xTL, yTL, xBR, yBR, poc, currentFeatures, quartersFeatures)
					index += 1
		df['videoname'] = self.videoName
		df['CU_width']  = CU_width
		df['CU_height'] = CU_height

		df = df.query('bottomRight_x <= 416 & bottomRight_y <= 240')
		df.reset_index(drop = True, inplace = True)
		return df

	def calcFeatures(self, imageInput, xTL, yTL, xBR, yBR):
	    lineFeatures = []
	    gradH = ndimage.sobel(imageInput[yTL:yBR+1,xTL:xBR+1], axis = 1, mode='nearest').sum(dtype = np.uint16)
	    gradV = ndimage.sobel(imageInput[yTL:yBR+1,xTL:xBR+1], axis = 0, mode='nearest').sum(dtype = np.uint16)
	    var   = np.var(imageInput[yTL:yBR+1,xTL:xBR+1])
	    mean  = np.mean(imageInput[yTL:yBR+1,xTL:xBR+1])
	    s     = np.sum(imageInput[yTL:yBR+1,xTL:xBR+1])

	    if gradV != 0:
	    	ratioGrad = float(gradH) / float(gradV)
	    else:
	    	ratioGrad = 0

	    lineFeatures.append([var, mean, gradH, gradV, ratioGrad, s])

	    return lineFeatures[0]
	
	def quarterSplit(self, imageInput, CU_height, CU_width, xTL, yTL, xBR, yBR, split):
		quartersFeatures = []
		triControl = 0
		for h in range(yTL, yBR, CU_height):
			for w in range(xTL, xBR, CU_width):
				
				QxTL = w
				QyTL = h
				QxBR = w + CU_width  - 1
				QyBR = h + CU_height - 1

				if ((split == 'TRI_HORZ') or (split == 'TRI_VERT')):

					if triControl == 1:
						triControl += 1
						continue
					
					elif triControl == 2:

						if split == 'TRI_HORZ':
							triControl += 1
							yTL = h - CU_height
						elif split == 'TRI_VERT':
							triControl += 1
							xTL = w - CU_width

				currentFeatures = self.calcFeatures(imageInput, QxTL, QyTL, QxBR, QyBR)
				quartersFeatures.append(currentFeatures)
				triControl += 1

		return quartersFeatures

	def writeDataFrame(self, df, index, split, xTL, yTL, xBR, yBR, POC, currentFeatures, quartersFeatures):
		if split == 'QT_SPLIT':
			df.loc[index] = [xTL, yTL, xBR, yBR, POC, currentFeatures[0], currentFeatures[1], currentFeatures[2], currentFeatures[3], currentFeatures[4], currentFeatures[5],
							quartersFeatures[0][0], quartersFeatures[0][1], quartersFeatures[0][2], quartersFeatures[0][3], quartersFeatures[0][4], quartersFeatures[0][5],
							quartersFeatures[1][0], quartersFeatures[1][1], quartersFeatures[1][2], quartersFeatures[1][3], quartersFeatures[1][4], quartersFeatures[1][5],
							quartersFeatures[2][0], quartersFeatures[2][1], quartersFeatures[2][2], quartersFeatures[2][3], quartersFeatures[2][4], quartersFeatures[2][5],
							quartersFeatures[3][0], quartersFeatures[3][1], quartersFeatures[3][2], quartersFeatures[3][3], quartersFeatures[3][4], quartersFeatures[3][5]]
		if ((split == 'BI_HORZ') or (split == 'BI_VERT')):
			df.loc[index] = [xTL, yTL, xBR, yBR, POC, currentFeatures[0], currentFeatures[1], currentFeatures[2], currentFeatures[3], currentFeatures[4], currentFeatures[5],
							quartersFeatures[0][0], quartersFeatures[0][1], quartersFeatures[0][2], quartersFeatures[0][3], quartersFeatures[0][4], quartersFeatures[0][5],
							quartersFeatures[1][0], quartersFeatures[1][1], quartersFeatures[1][2], quartersFeatures[1][3], quartersFeatures[1][4], quartersFeatures[1][5],
							-1, -1, -1, -1, -1, -1,
							-1, -1, -1, -1, -1, -1]

		if ((split == 'TRI_HORZ') or (split == 'TRI_VERT')):
			df.loc[index] = [xTL, yTL, xBR, yBR, POC, currentFeatures[0], currentFeatures[1], currentFeatures[2], currentFeatures[3], currentFeatures[4], currentFeatures[5],
							quartersFeatures[0][0], quartersFeatures[0][1], quartersFeatures[0][2], quartersFeatures[0][3], quartersFeatures[0][4], quartersFeatures[0][5],
							quartersFeatures[1][0], quartersFeatures[1][1], quartersFeatures[1][2], quartersFeatures[1][3], quartersFeatures[1][4], quartersFeatures[1][5],
							quartersFeatures[2][0], quartersFeatures[2][1], quartersFeatures[2][2], quartersFeatures[2][3], quartersFeatures[2][4], quartersFeatures[2][5],
							-1, -1, -1, -1, -1, -1]