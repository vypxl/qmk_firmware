#! /usr/bin/env python


def main():
    r = range(26)
    a = list(chr(ord('a') + x) for x in r)
    a += [
        "left",
        "right",
        "up",
        "down",
    ]

    for i in range(26):
        print(f"#define {a[i]} KC_{a[i].upper()}")

    for i in range(26):
        print(f"#undef {a[i]}")


if __name__ == "__main__":
    main()
