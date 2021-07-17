from datasetCleaner import *
import numpy as np
import pandas as pd 
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn_porter import Porter

types = ['s0', 's1', 's2', 's3', 's4', 's5', 's6']

for t in types:
	
	cleaner = datasetCleaner(path1 = 'QT_SPLIT', path2 = None, div = t)
	print('\nDATASET: {}'.format(t))
	
	if cleaner.verifyClasses():
		cleaner.duplicatedFeatures()
		#print('\tTYPE: QT_SPLIT \t ACC: {}'.format(cleaner.fastTraining()))
		
	cleaner = datasetCleaner(path1 = 'BI_HORZ', path2 = 'TRI_HORZ', div = t)
	
	if cleaner.verifyClasses():
		cleaner.duplicatedFeatures()
		#print('\tTYPE: HORZ \t ACC: {}'.format(cleaner.fastTraining()))
	
	cleaner = datasetCleaner(path1 = 'BI_VERT', path2 = 'TRI_VERT', div = t)
	
	if cleaner.verifyClasses():
		cleaner.duplicatedFeatures()
		#print('\tTYPE: VERT \t ACC: {}'.format(cleaner.fastTraining()))
