#!/usr/bin/python3

from random import randint
import sys
from secrets import token_hex as rand_hex

def main():
    argument = sys.argv[1]
    print(argument)

    if "-h" in argument:
        print("[NUM]* = [NUM] random bytes")
        print("** = random number of random bytes")
        print("? = 1 random half hex byte ('??' for a byte)")
        exit(0)
    
    bytes_ = input("hex bytes : ").split(" ")
    print(bytes_)

    open(argument, 'w').close()
    handle = open(argument, 'ab+')

    handle.write(bytes(format_input(bytes_)))

    handle.close()



def format_input(bytes_):
    bytelist_formatted = []
    buffer_tmp = ''
    buffer_formatted = ''
    list_wildcard = []

    for byte in bytes_:
        #print("BYTE : ", byte)
        buffer_tmp = byte
        buffer_formatted = ''
        list_wildcard = []
        if buffer_tmp[-1] == '*':
            if buffer_tmp[:-1] == '*':
                nb_of_bytes = randint(1, 20)
            else:
                try:
                    nb_of_bytes = int(buffer_tmp[:-1])
                except:
                    print("Wrong number of bytes before wildcard")
                    exit(0)

            list_wildcard = split_n(rand_hex(nb_of_bytes), 2)
            # print(list_wildcard)
            for i in list_wildcard:
                bytelist_formatted.append(int(i, 16))

        else:
            for char in buffer_tmp:
                # print("CHAR : ")
                if char == '?':
                    buffer_formatted += rand_hex(1)[0]
                else:
                    buffer_formatted += char
            bytelist_formatted.append(int(buffer_formatted, 16))
        
    return bytelist_formatted


def split_n(s, chunk_size):
    a = zip(*[s[i::chunk_size] for i in range(chunk_size)])
    return [''.join(t) for t in a]

if __name__ == "__main__":
    main()