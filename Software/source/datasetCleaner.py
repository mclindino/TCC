import numpy as np
import pandas as pd
from sklearn.feature_selection import VarianceThreshold
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score

class datasetCleaner:

	def __init__(self, path1 = None, path2 = None, div = None):
		df1 = pd.read_csv('../datasets/' + path1 + '/' + div + '.csv')

		if path2 == None:
			self.df = df1.drop(columns = ['videoname', 'splitType', 'cost', 'RDCost'])
		
		else:
			df2 = pd.read_csv('../datasets/' + path2 + '/' + div + '.csv')
			dfBoth = pd.concat([df1, df2])
			dfBoth.reset_index(inplace = True, drop = True)
			self.df = dfBoth.drop(columns = ['videoname', 'splitType', 'cost', 'RDCost'])

		self.X = 0
		self.y = 0

	def getDataFrame(self):
		return self.df

	def verifyClasses(self):
		return self.df['target'].value_counts().shape[0] > 1
		
	def duplicatedFeatures(self):

		self.X = self.df.drop(columns = ['target'])
		self.y = self.df['target']

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

	def fastTraining(self):
		forest = RandomForestClassifier(random_state = 0)
		scores = cross_val_score(forest, self.X, self.y, cv = 10, n_jobs = 2)
		return scores.mean()