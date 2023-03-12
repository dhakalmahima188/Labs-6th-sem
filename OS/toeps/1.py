from PIL import Image
import os

# Set the path to the folder containing the PNG files
png_folder = './os_output/'

# Set the path to the folder where the EPS files will be saved
eps_folder = './os_outputeps/'

# Loop through all the files in the PNG folder
for filename in os.listdir(png_folder):
    if filename.endswith('.png'):
        # Open the PNG file and convert it to EPS format
        with Image.open(os.path.join(png_folder, filename)) as img:
            img.save(os.path.join(eps_folder, os.path.splitext(filename)[0] + '.eps'), 'EPS')