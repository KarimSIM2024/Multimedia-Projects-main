# Multimedia Projects : Image File Extension Reader

This repository contains various multimedia-related projects. Below is an explanation of the file currently included:

## File: `Final.c`

### Description:
This file provides a C program that identifies the type of a multimedia file based on its magic numbers (file header). The program reads the first few bytes of the file and matches them against known headers for common file formats.

### Features:
- Detects the following file types:
  - JPEG
  - PNG
  - GIF
  - BMP
  - TIFF (both little-endian and big-endian)
- Provides error handling for invalid or small files.

### Implementation:
- Reads the first 8 bytes of the file.
- Matches the header bytes to predefined values for each file format.
- Outputs the file type or an error message if the type is unknown.

### Use Cases:
This program is useful for:
- File validation in multimedia applications.
- Quick identification of file formats in a batch of files.
- Educational purposes for understanding magic numbers in file headers.

