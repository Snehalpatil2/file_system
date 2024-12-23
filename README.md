# Virtual Disk Management System

## Overview

The **Virtual Disk Management System** is a file system simulation implemented in C. It allows users to create, add, retrieve, and list files within a virtual disk. The system operates on Linux and provides an efficient way to handle files through metadata encoding and decoding.

## Features

- **File Addition**: Add files to the virtual disk while encoding file names and sizes.
- **File Retrieval**: Retrieve files from the virtual disk based on file metadata.
- **File Listing**: List all files stored in the virtual disk with their sizes.
- **Virtual Disk Creation**: Initialize a new virtual disk for file storage.

## Build System

This project uses a **Makefile** to compile and manage dependencies efficiently.

### Makefile Targets

- **all**: Compiles all executables (`create_vd`, `vd_add`, `vd_get`, `vd_ls`).
- **create_vd**: Creates the virtual disk.
- **vd_add**: Adds a file to the virtual disk.
- **vd_get**: Retrieves a file from the virtual disk.
- **vd_ls**: Lists all files in the virtual disk.
- **clean**: Removes all compiled files and object files.

### Compilation Commands

- Each `.o` file is compiled using `gcc -c`.
- The archive `arc.a` is created with `ar rcs`.
- Final executables are linked using `gcc`.

## Code Structure

### 1. `create_vd.c`
- Initializes a new virtual disk file and prepares it for use.
- Sets up metadata for file storage.

### 2. `vd_add.c`
- Adds a file to the virtual disk:
  - Opens the virtual disk and the input file.
  - Encodes the file name and size using the `encode` function.
  - Appends the file data to the virtual disk while updating metadata.

### 3. `vd_get.c`
- Retrieves a file from the virtual disk:
  - Reads metadata to locate the file.
  - Decodes file name and size using the `decode_file` function.
  - Extracts the file content and writes it to an output file.

### 4. `vd_ls.c`
- Lists all files in the virtual disk:
  - Decodes metadata to display file names and sizes.

### 5. `encode.c`
- Encodes file names and metadata for storage in the virtual disk.

### 6. `decode_file.c`
- Decodes metadata to retrieve file names and sizes.

## Usage

### Build the Project

To compile all components, run:

```bash
make all
```

### Create a Virtual Disk

To create a new virtual disk, use the following command:

```bash
./create_vd <disk_size> <disk_name>
```

### Add a File to the Virtual Disk

To add a file to the virtual disk, run:

```bash
./vd_add <disk_name> <file_path>
```

### Retrieve a File from the Virtual Disk

To retrieve a file from the virtual disk, run:

```bash
./vd_get <disk_name> <file_index> <output_file>
```

Where `<file_index>` is the index of the file you want to retrieve and `<output_file>` is the path where the file will be saved.

### List All Files in the Virtual Disk

To list all files in the virtual disk, run:

```bash
./vd_ls <disk_name>
```

### Clean Build Artifacts

To remove all compiled files and object files, run:

```bash
make clean
```

## Author

Snehal Jitendra Patil

