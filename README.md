## Steganography Program

# Overview
This program lets you hide secret messages inside PPM image files and retrieve them later. It works by encoding messages in the least significant bits of the image’s pixel data, so the hidden message doesn’t visibly alter the image.

# To Run
- Make the project and then follow the terminal prompts to complete the actions.


# What Was Hard?

Getting the Makefile to work on Windows was tricky since some commands like rm don’t work there. Switching to Git Bash or tweaking the Makefile helped.
Debugging why some PPM files wouldn’t decode correctly took time—turns out, they weren’t properly formatted.

# How We Worked Together
We divided the work by focusing on different parts of the program (encoding, decoding, and testing).
When we hit issues, we debugged them together, like fixing Windows compatibility or testing edge cases with the PPM files.
That’s it!