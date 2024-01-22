
from pycaret.regression import *
import pandas as pd


data = {
    'vec1': [1, 2, 3, 4, 5],
    'vec2': [5, 4, 3, 2, 1],
    'vec3': [10, 20, 30, 40, 50],
    '1try': [15, 25, 35, 45, 55],
    '2try': [20, 30, 40, 50, 60],
    '3try': [25, 35, 45, 55, 65],
    '4try': [30, 40, 50, 60, 70],
    '5try': [35, 45, 55, 65, 75],
    '6try': [40, 50, 60, 70, 80],
    '7try': [45, 55, 65, 75, 85]
}

df = pd.DataFrame(data)

print(len(df)) 












