import numpy as np
import pandas as pd
from sklearn.feature_selection import VarianceThreshold
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score
from warnings import simplefilter
simplefilter(action='ignore', category=FutureWarning)
from sklearn_porter import Porter
import fileinput
from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import f_classif
from os import system
import argparse
from imblearn.over_sampling import SMOTE 

parser = argparse.ArgumentParser() 
parser.add_argument('--dataset', '-d')
parser.add_argument('--split', '-s')
args = parser.parse_args()

div = args.dataset
split = args.split

df = pd.read_csv('../datasets/' + split + '/' + div + '.csv')

df.drop(columns = ['videoname', 'splitType', 'cost'], inplace = True)
X = df.drop(columns = 'target')
y = df['target'].astype(int)

constant_filter = VarianceThreshold(threshold = 0.01)
constant_filter.fit(X)
xFilter = constant_filter.transform(X)
columnsFilter = X.columns[constant_filter.get_support()]

x_T = xFilter.T
x_T = pd.DataFrame(x_T)

duplicatedFeatures = x_T.duplicated()
featuresToKeep = [not index for index in duplicatedFeatures]

xUnique = x_T[featuresToKeep].T
columnsUnique = columnsFilter[featuresToKeep]

xUnique.columns = columnsUnique
X = xUnique

sm = SMOTE(random_state = 42)
X, y = sm.fit_resample(X, y)

forest = RandomForestClassifier(random_state = 42, class_weight = 'balanced')
forest.fit(X, y)
scores = cross_val_score(forest, X, y, cv = 5, n_jobs = -1)
print('Dataset: ' + div + '\t Split: ' + split + ' \t Score: ' + str(scores.mean()))

file = open('../datasets/' + split + '/' + div + '_' + split + '.cpp', 'w')

porter = Porter(forest, language='c')
output = porter.export(embed_data=True)
file.write(output)
file.close()
			
library = []
for i in range(100):
	with fileinput.FileInput('../datasets/' + split + '/' + div + '_' + split + '.cpp', inplace = True) as file:
		for line in file:
			print(line.replace('predict_' + str(i), 'predict_' + str(i) + '_' + div + '_' + split), end = '')

with fileinput.FileInput('../datasets/' + split + '/' + div + '_' + split + '.cpp', inplace = True) as file:
	for line in file:
		print(line.replace('predict (', 'predict_' + div + '_' + split + ' ('), end = '')

with open('../datasets/' + split + '/' + div + '_' + split + '.cpp', "r+") as f:
	d = f.readlines()
	library = d[0:4]
	f.seek(0)
	f.write('#include \"' + div + "_" + split + '.h\"\n')
	for i in range(4,len(d)-10):
		f.write(d[i])
	f.truncate()
	
library_file = open('../datasets/' + split + '/' + div + '_' + split + '.h', 'w')
library_file.writelines(library)
library_file.write('int predict_' + div + '_' + split + '(float features[]);')
library_file.close()

features = X.columns
features_file = open('../datasets/' + split + '/features_' + div + '_' + split + '.txt', 'w')
features_file.write('float features_' + div + '_' + split + '[' + str(features.shape[0]) + '];\n')

for f in range(features.shape[0]):
	features_file.write('features_' + div + '_' + split + '[' + str(f) + '] = f_' + features[f] + ';\n')
features_file.close()

file = '../datasets/' + split + '/' + div + '_' + split 
cmd = 'mv ' + file + '.h ../../VTM-9.0/source/Lib/EncoderLib/'  + div + '_' + split + '.h;' 'mv ' + file + '.cpp ../../VTM-9.0/source/Lib/EncoderLib/' + div + '_' + split + '.cpp'
system(cmd)
