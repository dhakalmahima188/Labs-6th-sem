import torch
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
# Reshaping, stacking-comnbine esnors, squeezing-removes 1D , unsqueezing adds 1D
y = torch.arange(1, 9)
z=torch.arange(10, 18)
print(y, y.shape)
y_res = y.reshape(2, 4)
print(y_res, y_res.shape)
y_stacked=torch.stack((y, z), dim=0)
print(y_stacked, y_stacked.shape,y_stacked.squeeze(), y_stacked.squeeze().shape)
new_tens=torch.tensor([[1, 2, 3, 4]])
print(new_tens.shape,new_tens.squeeze(),new_tens.squeeze().shape) # squeeze removes 1D
print(new_tens.unsqueeze(0),new_tens.unsqueeze(0).shape) # unsqueeze adds 1D
#permute
#buzena
xyz=torch.permute(new_tens,(2,1))
print(xyz,xyz.size())