# 🖼️ Filter

This project applies various image processing filters to BMP image files. It includes filters like **grayscale**, **sepia**, **reflect**, and **blur**, all implemented from scratch.

## 🧰 Features

- 🎨 **Grayscale** – Converts the image to shades of gray
- 🟤 **Sepia** – Applies a warm, antique tone
- 🔄 **Reflect** – Mirrors the image horizontally
- 🌫️ **Blur** – Applies a box blur effect to smooth the image

## ⚙️ How It Works

Each filter manipulates pixel data directly by adjusting RGB values:

- **Grayscale**: Averages red, green, and blue values per pixel.
- **Sepia**: Applies the sepia formula:  

sepiaRed = .393R + .769G + .189B  
sepiaGreen = .349R + .686G + .168B  
sepiaBlue = .272R + .534G + .131*B  
- **Reflect**: Swaps pixels across the horizontal center line.
- **Blur**: Averages the color values of surrounding pixels.

## 🧪 Example Usage (C version)
Original Image:  
<img src="https://github.com/user-attachments/assets/d3dee4ae-6423-4968-8d78-c17fc314ba78" alt="Screenshot 2025-05-23 235914" width="500"/>
```bash
$ ./filter -g input.bmp output.bmp   # Grayscale
```
<img src="https://github.com/user-attachments/assets/c0f2a953-96c2-442a-840c-0a66024e3def" alt="Screenshot 2025-05-23 235914" width="500"/>

```
$ ./filter -s input.bmp output.bmp   # Sepia
```
<img src="https://github.com/user-attachments/assets/90bc9799-b37b-4c77-8fbf-79356723232e" alt="Screenshot 2025-05-23 235914" width="500"/>

```
$ ./filter -r input.bmp output.bmp   # Reflect
```
<img src="https://github.com/user-attachments/assets/a8d8e30e-4de7-4a15-8c8d-7353090e7fd0" alt="Screenshot 2025-05-23 235914" width="500"/>

```
$ ./filter -b input.bmp output.bmp   # Blur
```
<img src="https://github.com/user-attachments/assets/0184c76c-f46f-47ae-abd4-880b43255ee8" alt="Screenshot 2025-05-23 235914" width="500"/>

