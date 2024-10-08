
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// A Tree node
typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

// Comparison function to be used to order the heap
int comp(Node* l, Node* r) {
    // highest priority item has lowest frequency
    return l->freq > r->freq;
}

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, char* str, char** huffmanCode, int* top) {
    if (root == NULL)
        return;

    // found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[*top] = (char*)malloc(strlen(str) + 1);
        strcpy(huffmanCode[*top], str);
        (*top)++;
    }

    int len = strlen(str);
    char* left_str = (char*)malloc(len + 2);
    strcpy(left_str, str);
    strcat(left_str, "0");
    encode(root->left, left_str, huffmanCode, top);
    free(left_str);

    char* right_str = (char*)malloc(len + 2);
    strcpy(right_str, str);
    strcat(right_str, "1");
    encode(root->right, right_str, huffmanCode, top);
    free(right_str);
}

// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int* index, char* str, char* res, int* top) {
    if (root == NULL) {
        return;
    }

    // found a leaf node
    if (!root->left && !root->right) {
        res[*top] = root->ch;
        (*top)++;
        return;
    }

    (*index)++;

    if (str[*index] == '0')
        decode(root->left, index, str, res, top);
    else
        decode(root->right, index, str, res, top);
}

void print_heap(Node** heap, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c %d\n", heap[i]->ch, heap[i]->freq);
    }
}

char* getEncodedData(char* text, Node* root) {
    // print encoded string
    char** huffmanCode = (char**)calloc(256, sizeof(char*));
    int top = 0;
    encode(root, "", huffmanCode, &top);

    printf("Huffman Codes are :\n\n");
    for (int i = 0; i < top; i++) {
        printf("%c %s\n", huffmanCode[i][0], huffmanCode[i] + 1);
    }

    printf("\nOriginal string was :\n%s\n", text);

    // print encoded string
    int len = strlen(text);
    char* str = (char*)malloc(len * 8 + 1);
    int idx = 0;
    for (int i = 0; i < len; i++) {
        char ch = text[i];
        for (int j = 0; j < top; j++) {
            if (huffmanCode[j][0] == ch) {
                strcat(str, huffmanCode[j] + 1);
                break;
            }
        }
    }

    printf("\nEncoded string is :\n%s\n", str);
    return str;
}

void getDecodedData(Node* root, char* encodedData) {
    int index = -1;
    printf("\nDecoded string is: \n");
    char res[1000] = {0};
    int top = 0;
    while (index < (int)strlen(encodedData) - 2) {
        decode(root, &index, encodedData, res, &top);
    }
    res[top] = '\0';
    printf("%s", res);
}

// Builds Huffman Tree and decode given input text
Node* buildHuffmanTree(char* text) {
    // count frequency of appearance of each character
    // and store it in a map
    int freq[256] = {0};
    for (int i = 0; text[i]; i++) {
        freq[text[i]]++;
    }

    // Create a priority queue to store live nodes of
    // Huffman tree;
    Node** heap = (Node**)malloc(256 * sizeof(Node*));
    int size = 0;

    // Create a leaf node for each character and add it
    // to the priority queue.
    for (int i = 0; i < 256; i++) {
        if (freq[i]) {
            heap[size++] = getNode(i, freq[i], NULL, NULL);
        }
    }

    // print_heap(heap, size);

    // do till there is more than one node in the queue
    while (size != 1) {
        // Remove the two nodes of highest priority
        // (lowest frequency) from the queue
        Node* left = heap[0];
        for (int i = 0; i < size - 1; i++) {
            heap[i] = heap[i + 1];
        }
        size--;

        Node* right = heap[0];
        for (int i = 0; i < size - 1; i++) {
            heap[i] = heap[i + 1];
        }
        size--;

        // Create a new internal node with these two nodes
        // as children and with frequency equal to the sum
        // of the two nodes' frequencies. Add the new node
        // to the priority queue.
        int sum = left->freq + right->freq;
        Node* new_node = getNode('\0', sum, left, right);
        for (int i = size; i > 0; i--) {
            if (comp(new_node, heap[i - 1])) {
                heap[i] = heap[i - 1];
            } else {
                heap[i] = new_node;
                size++;
                break;
            }
        }
    }

    // root stores pointer to root of Huffman Tree
    Node* root = heap[0];
    free(heap);
    return root;
}

char* readData(char* fileName) {
    FILE* f = fopen(fileName, "r");
    if (!f) {
        printf("Unable to open the file.\n");
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    char* data = (char*)malloc(size + 1);
    fread(data, 1, size, f);
    data[size] = '\0';

    fclose(f);
    return data;
}

int main() {
    char filePath[100];
    printf("Enter file path: ");
    scanf("%s", filePath);
    char* text = readData(filePath);
    if (text == NULL) {
        return 1;
    }
    Node* root = buildHuffmanTree(text);
    char* encodedMsg = getEncodedData(text, root);
    getDecodedData(root, encodedMsg);
    free(text);
    free(encodedMsg);
    return 0;
}

