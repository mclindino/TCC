from datasetCleaner import *
from pixelFeatures import *
import sys
from os import system

def main():
	types = ['s0']#, 's1', 's2', 's3', 's4', 's5', 's6']
	pf = pixelFeatures('1', 1, 1, 1, 1)

	for t in types:
		
		print('\nDATASET: {}'.format(t))
		#pf.concatenateDataFrames(path1 = 'VTM_MinMin', path2 = t)
		cleaner = datasetCleaner(path1 = 'QT_SPLIT', path2 = None, div = t)

		if cleaner.verifyClasses():
			cleaner.duplicatedFeatures()
			print('\tTYPE: QT_SPLIT \t ACC: {}'.format(cleaner.fastTraining(False)))
			cleaner.fastTraining(True, t, 'QT_SPLIT')
			print('\t\tPORTER COMPLETE')

			file = '../datasets/models/QT_SPLIT/' + t + '_QT_SPLIT'
			cmd = 'mv ' + file + '.h ../../VTM-9.0/source/Lib/EncoderLib/'  + t + '_QT_SPLIT.h;' 'mv ' + file + '.cpp ../../VTM-9.0/source/Lib/EncoderLib/' + t + '_QT_SPLIT.cpp'
			system(cmd)

		else:
			print('\tNO QT_SPLIT')

		cleaner = datasetCleaner(path1 = 'BI_HORZ', path2 = 'TRI_HORZ', div = t)
		
		if cleaner.verifyClasses():
			cleaner.duplicatedFeatures()
			print('\tTYPE: HORZ_SPLIT \t ACC: {}'.format(cleaner.fastTraining(False)))
			cleaner.fastTraining(True, t, 'HORZ_SPLIT')
			print('\t\tPORTER COMPLETE')

			file = '../datasets/models/HORZ_SPLIT/' + t + '_HORZ_SPLIT'
			cmd = 'mv ' + file + '.h ../../VTM-9.0/source/Lib/EncoderLib/'  + t + '_HORZ_SPLIT.h;' 'mv ' + file + '.cpp ../../VTM-9.0/source/Lib/EncoderLib/' + t + '_HORZ_SPLIT.cpp'
			system(cmd)

		else:
			print('\tNO HORZ')
		cleaner = datasetCleaner(path1 = 'BI_VERT', path2 = 'TRI_VERT', div = t)
		
		if cleaner.verifyClasses():
			cleaner.duplicatedFeatures()
			print('\tTYPE: VERT_SPLIT \t ACC: {}'.format(cleaner.fastTraining(False)))
			cleaner.fastTraining(True, t, 'VERT_SPLIT')
			print('\t\tPORTER COMPLETE')

			file = '../datasets/models/VERT_SPLIT/' + t + '_VERT_SPLIT'
			cmd = 'mv ' + file + '.h ../../VTM-9.0/source/Lib/EncoderLib/'  + t + '_VERT_SPLIT.h;' 'mv ' + file + '.cpp ../../VTM-9.0/source/Lib/EncoderLib/' + t + '_VERT_SPLIT.cpp'
			system(cmd)

		else:
			print('\tNO VERT')
	return 0

if __name__ == '__main__':
    sys.exit(main())