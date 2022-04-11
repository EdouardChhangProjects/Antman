#!/bin/env python3

import os

def check_file(fp:str):
    with open(fp, "r") as fd:
        original = fd.readlines()
        size_original = os.path.getsize(fp)
        fd.close()
    os.system(f"../ant \"{fp}\" > ./tmp.txt")
    size_compressed = os.path.getsize("./tmp.txt")
    os.system("../giant ./tmp.txt > ./final.txt")
    with open("./final.txt", "r") as fd:
        compressed = fd.readlines()
        fd.close()
    index:int = 0
    same:int = 1
    for i in range(len(original)):
        index += 1
        if i >= len(compressed):
            print(f"pas bon à la ligne {index} :\noriginal : \n{original[i]}\ncompressed : TOO SHORT!")
            return 84
        if original[i] != compressed[i]:
            same = 0
            print(f"pas bon à la ligne {index} :\noriginal : \n{original[i]}\ncompressed : \n{compressed[i]}\n")
    if same == 1:
        print(f"The file was compressed and reduced to {((size_compressed) / size_original) * 100}% of its original size.")
        print("No information was lost")
        return 0
    return 84

def main() -> int:
    ret:int = 0
    os.system("make -C ..")
    #check_file("trash.txt")
    for file in os.scandir("./assets/txt/"):
        print(f"\n>  >  >  >  >{file.name}\n")
        ret |= check_file("./assets/txt/" + file.name)
    print("---------------------------------------------LYR----------------------------------------------")
    for file in os.scandir("./assets/lyr"):
        print(f"\n>  >  >  >  >{file.name}\n")
        ret |= check_file("./assets/lyr/" + file.name)
    for file in os.scandir("./assets/extra"):
        print(f"\n>  >  >  >  >{file.name}\n")
        ret |= check_file("./assets/extra/" + file.name)    
"""    print("---------------------------------------------PPM----------------------------------------------")
    for file in os.scandir("./assets/ppm"):
        print(f"\n>  >  >  >  >{file.name}\n")
        ret |= check_file("./assets/ppm/" + file.name)
    return ret

    print("---------------------------------------------HTML---------------------------------------------")
    for file in os.scandir("./assets/html"):
        print(f"\n>  >  >  >  >{file.name}\n")
        ret |= check_file("./assets/html/" + file.name)"""

if __name__ == "__main__":
    exit(main())
