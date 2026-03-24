#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    const char *en;
    const char *th;
} KeyMap;

// key-mapping
const KeyMap MAP[] = {
    // --- Non-Shift Row ---
    {"1", "ๅ"}, {"2", "/"}, {"3", "_"}, {"4", "ภ"}, {"5", "ถ"}, {"6", "ุ"}, {"7", "ึ"}, {"8", "ค"}, {"9", "ต"}, {"0", "จ"}, {"-", "ข"}, {"=", "ช"},
    {"q", "ๆ"}, {"w", "ไ"}, {"e", "ำ"}, {"r", "พ"}, {"t", "ะ"}, {"y", "ั"}, {"u", "ี"}, {"i", "ร"}, {"o", "น"}, {"p", "ย"}, {"[", "บ"}, {"]", "ล"}, {"\\", "ฃ"},
    {"a", "ฟ"}, {"s", "ห"}, {"d", "ก"}, {"f", "ด"}, {"g", "เ"}, {"h", "้"}, {"j", "่"}, {"k", "า"}, {"l", "ส"}, {";", "ว"}, {"'", "ง"},
    {"z", "ผ"}, {"x", "ป"}, {"c", "แ"}, {"v", "อ"}, {"b", "ิ"}, {"n", "ื"}, {"m", "ท"}, {",", "ม"}, {".", "ใ"}, {"/", "ฝ"},

    // --- Shifted Row ---
    {"!", "+"}, {"@", "๑"}, {"#", "๒"}, {"$", "๓"}, {"%", "๔"}, {"^", "ู"}, {"&", "฿"}, {"*", "๕"}, {"(", "Z"}, {")", "X"}, {"_", "๘"}, {"+", "๙"},
    {"Q", "๐"}, {"W", "\""}, {"E", "ฎ"}, {"R", "ฑ"}, {"T", "ธ"}, {"Y", "ํ"}, {"U", "๊"}, {"I", "ณ"}, {"O", "ฯ"}, {"P", "ญ"}, {"{", "ฐ"}, {"}", ","}, {"|", "ฅ"},
    {"A", "ฤ"}, {"S", "ฆ"}, {"D", "ฏ"}, {"F", "โ"}, {"G", "ฌ"}, {"H", "็"}, {"J", "๋"}, {"K", "ษ"}, {"L", "ศ"}, {":", "ซ"}, {"\"", "."},
    {"Z", "("}, {"X", ")"}, {"C", "ฉ"}, {"V", "ฮ"}, {"B", "ฺ"}, {"N", "์"}, {"M", "?"}, {"<", "ฒ"}, {">", "ฬ"}, {"?", "ฦ"}
};

const int MAP_SIZE = sizeof(MAP) / sizeof(KeyMap);

void translate_char(const char *input, int *index) {
    unsigned char c = (unsigned char)input[*index];
    int found = 0;

    // 1. check-th (UTF-8 3-byte)
    if (c >= 0xE0) {
        char th_char[4] = {input[*index], input[*index + 1], input[*index + 2], '\0'};
        for (int j = 0; j < MAP_SIZE; j++) {
            if (strcmp(th_char, MAP[j].th) == 0) {
                printf("%s", MAP[j].en);
                found = 1;
                break;
            }
        }
        if (!found) printf("%s", th_char);
        *index += 3;
    }
    // 2. check eng/symbol(1-byte)
    else {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (input[*index] == MAP[j].en[0]) {
                printf("%s", MAP[j].th);
                found = 1;
                break;
            }
        }
        if (!found) printf("%c", input[*index]);
        *index += 1;
    }
}

int main(int argc, char *argv[]) {
    //support UTF-8 on Terminal (Mac/Linux)
    setlocale(LC_ALL, "en_US.UTF-8");

    if (argc < 2) {
        printf("Usage: langfix <text>\n");
        printf("Quick Fix: alias fix='langfix \"$*\"'\n");
        return 0;
    }

    // loop every Argument
    for (int i = 1; i < argc; i++) {
        int char_idx = 0;
        int word_len = strlen(argv[i]);
        while (char_idx < word_len) {
            translate_char(argv[i], &char_idx);
        }
        if (i < argc - 1) printf(" "); // เติมช่องว่างระหว่างคำ(idk what sould i put in eng)
    }
    printf("\n");

    return 0;
}
