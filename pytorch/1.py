import torch


print(torch.__version__)
scalar = torch.tensor(7)
vector = torch.tensor([[1, 2, 3, 4, 5], [1, 2, 3, 4, 5]])
print(vector.shape)  # 5 2*5 element
print(vector.ndim)  # 2 dimension
print(scalar.ndim)
print(scalar.item())
matrix = torch.tensor([[1, 2, 3, 4, 5], [1, 2, 3, 4, 5], [
                      1, 2, 3, 4, 5]], dtype=torch.float32, device=None, requires_grad=False)  # tracking gradient
float_16 = matrix.type(torch.float16)  # typecasting
print(float_16.dtype)
# print(matrix)
TENSOR = torch.tensor([[[1, 2], [3, 4]]])
print(TENSOR.shape)
# creating tensors
# random tensors : cnn starts with random numbers : update reandom numbes
random_tensor = torch.rand((3, 3))
print(random_tensor.ndim)
# height,width, rgb color channel
random_image_tensor = torch.rand(size=(3, 3, 3))
# zeros and ones initializsation
zero_tensor = torch.zeros((3, 3))
one_tensor = torch.ones((3, 3))
print(zero_tensor, one_tensor)
# data type
print(one_tensor.dtype)  # by default float32
# range
print(torch.arange(0, 9))
# like
ten_zeros = torch.zeros_like(one_tensor)
print(ten_zeros)
# float32 tensor
# matrix multiplicatioan
mat = torch.tensor([[1, 2], [1, 2]])
mats = torch.matmul(mat, mat)
print(mats.T)  # transpose
print(mats)

value = 0
for i in range(len(mats)):
    value += mats[i]*mat[i]
print(value)
# inding mean max min
x = torch.rand((3, 3))
print(x, torch.min(x), torch.max(x), torch.mean(x))
# FINDING POSITION SOF MIN MAX
print(torch.argmin(x), torch.argmax(x))
