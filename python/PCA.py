import matplotlib.pyplot as plt

from sklearn import datasets
from sklearn.decomposition import PCA
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis

iris = datasets.load_iris()

X = iris.data
y = iris.target

target_names = iris.target_names
print('Espécies de Iris:\n')
print(target_names)

pca = PCA(n_components=2)

X_r = pca.fit(X).transform(X)
print('\nEixos PCA:\n')
print(X_r)

lda = LinearDiscriminantAnalysis(n_components=2)


X_r2 = lda.fit(X, y).transform(X)
print('\nEixos LDA:\n')
print(X_r2)
# Percentage of variance explained for each components
print('\nTaxa de variância explicada (primeiro de dois componentes): %s'
      % str(pca.explained_variance_ratio_))

#plt.figure()
plt.subplot(1,2,1)
for c, i, target_name in zip("rgb", [0, 1, 2], target_names):
    plt.scatter(X_r[y == i, 0], X_r[y == i, 1], c=c, label=target_name)
plt.legend()
plt.title('PCA of IRIS dataset')
plt.subplot(1,2,2)
#plt.figure()
for c, i, target_name in zip("rgb", [0, 1, 2], target_names):
    plt.scatter(X_r2[y == i, 0], X_r2[y == i, 1], c=c, label=target_name)
plt.legend()
plt.title('Linear Discriminant of IRIS dataset')
plt.show()
