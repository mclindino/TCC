import numpy as np
import pandas as pd
from sklearn.feature_selection import mutual_info_classif, VarianceThreshold
from sklearn.inspection import permutation_importance
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split

class datasetClean:
	
	def duplicatedFeatures(self, df):

		X = df.drop(columns = ['target'])
		y = df['target']

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

		return X, y

	def featuresImportance(self, X, y):
		X_train, X_test, y_train, y_test = train_test_split(X, y, stratify = y, random_state = 0)
		forest = RandomForestClassifier(random_state = 0)
		forest.fit(X, y)
		result = permutation_importance(forest, X_test, y_test, n_repeats = 10, random_state = 0, n_jobs = 2)
		forest_importances = pd.Series(result.importances_mean, index = X.columns)
		forest_importances.plot.bar(yerr = result.importances_std, figsize = (20,8))