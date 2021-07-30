import numpy as np
import pandas as pd
from sklearn.feature_selection import VarianceThreshold
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score
from warnings import simplefilter
simplefilter(action='ignore', category=FutureWarning)
from sklearn_porter import Porter
import fileinput
from imblearn.over_sampling import SMOTE

class datasetCleaner:

	def __init__(self, path1 = None, path2 = None, div = None):
		df1 = pd.read_csv('../datasets/' + path1 + '/' + div + '.csv')

		if path2 == None:
			self.df = df1.drop(columns = ['videoname', 'splitType'])
		
		else:
			df2 = pd.read_csv('../datasets/' + path2 + '/' + div + '.csv')
			dfBoth = pd.concat([df1, df2])
			dfBoth.reset_index(inplace = True, drop = True)
			self.df = dfBoth.drop(columns = ['videoname', 'splitType'])
			#self.df.replace([np.inf, -np.inf], -1, inplace=True)
			self.df = self.df.query('POC > 0')

		self.X = 0
		self.y = 0

	def getDataFrame(self):
		return self.df

	def verifyClasses(self):
		return self.df['target'].value_counts().shape[0] > 1
		
	def duplicatedFeatures(self):

		self.X = self.df.drop(columns = ['target']).astype(float)
		self.y = self.df['target'].astype(int)

		constant_filter = VarianceThreshold(threshold = 0.01)
		constant_filter.fit(self.X)
		xFilter = constant_filter.transform(self.X)
		columnsFilter = self.X.columns[constant_filter.get_support()]

		x_T = xFilter.T
		x_T = pd.DataFrame(x_T)

		duplicatedFeatures = x_T.duplicated()
		featuresToKeep = [not index for index in duplicatedFeatures]

		xUnique = x_T[featuresToKeep].T
		columnsUnique = columnsFilter[featuresToKeep]

		xUnique.columns = columnsUnique
		self.X = xUnique

		return 1

	def featuresImportance(self):
		forest = RandomForestClassifier(random_state = 0)
		forest.fit(self.X, self.y)
		importances = forest.feature_importances_
		std = np.std([tree.feature_importances_ for tree in forest.estimators_], axis = 0)
		forest_importances = pd.Series(importances, index = self.X.columns)
		forest_importances.plot.bar(yerr = std, figsize = (20,8));

	def fastTraining(self, returnMethod = False, div = None, split = None):
		#oversample = SMOTE()
		#self.X, self.y = oversample.fit_resample(self.X, self.y)
		forest = RandomForestClassifier(n_estimators = 10, random_state = 0)
		
		if returnMethod:
			forest.fit(self.X, self.y)
			file = open('../datasets/models/' + split + '/' + div + '_' + split + '.cpp', 'w')
			porter = Porter(forest, language='c')
			output = porter.export(embed_data=True)
			file.write(output)
			file.close()
			library = []
			for i in range(10):
				with fileinput.FileInput('../datasets/models/' + split + '/' + div + '_' + split + '.cpp', inplace = True) as file:
					for line in file:
						print(line.replace('predict_' + str(i), 'predict_' + str(i) + '_' + div + '_' + split), end = '')

			with fileinput.FileInput('../datasets/models/' + split + '/' + div + '_' + split + '.cpp', inplace = True) as file:
				for line in file:
					print(line.replace('predict (', 'predict_' + div + '_' + split + ' ('), end = '')

			with open('../datasets/models/' + split + '/' + div + '_' + split + '.cpp', "r+") as f:
				d = f.readlines()
				library = d[0:4]
				f.seek(0)
				f.write('#include \"' + div + "_" + split + '.h\"\n')
				for i in range(4,len(d)-10):
					f.write(d[i])
				f.truncate()
				
			library_file = open('../datasets/models/' + split + '/' + div + '_' + split + '.h', 'w')
			library_file.writelines(library)
			library_file.write('int predict_' + div + '_' + split + '(float features[]);')
			library_file.close()


			features = self.X.columns
			features_file = open('../datasets/models/' + split + '/features_' + div + '_' + split + '.txt', 'w')
			features_file.write('float features_' + div + '_' + split + '[' + str(features.shape[0]) + '];\n')
			for f in range(features.shape[0]):
				features_file.write('features_' + div + '_' + split + '[' + str(f) + '] = rf_' + features[f] + ';\n')
			features_file.close()

		else:
			scores = cross_val_score(forest, self.X, self.y, cv = 5, n_jobs = 2)
			return scores.mean()
