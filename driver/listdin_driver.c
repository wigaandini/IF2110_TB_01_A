#include <stdio.h>
#include "../adt/listdin.c"

#define here printf("HERE\n");

int main() {
    ListDin list1, list2, result;
    ElTypeDIN max, min;

    // Test CreateListDin
    CreateListDin(&list1, 5);
    CreateListDin(&list2, 5);

    // Test insertLast
    insertLast(&list1, 'A');
    insertLast(&list1, 'B');
    insertLast(&list1, 'C');
    insertLast(&list2, 'X');
    insertLast(&list2, 'Y');
    insertLast(&list2, 'Z');

    // Test printList
    printf("List 1: ");
    printList(list1);
    printf("\n");

    printf("List 2: ");
    printList(list2);
    printf("\n");

    // Test isListEqual
    if (isListEqual(list1, list2)) {
        printf("List 1 is equal to List 2\n");
    } else {
        printf("List 1 is not equal to List 2\n");
    }

    // Test plusMinusList
    result = plusMinusList(list1, list2, 1);
    printf("List 1 + List 2: ");
    printList(result);
    printf("\n");

    // Test extremeValues
    extremeValues(list1, &max, &min);
    printf("Max value in List 1: %c\n", max);
    printf("Min value in List 1: %c\n", min);

    // Test copyList
    ListDin copiedList;
    CreateListDin(&copiedList, 5);
    copyList(list1, &copiedList);
    printf("Copied List: ");
    printList(copiedList);
    printf("\n");

    // Test sumList
    ElTypeDIN sum = sumList(list1);
    printf("Sum of List 1: %c\n", sum);

    // Test countVal
    int countA = countVal(list1, 'A');
    printf("Count of 'A' in List 1: %d\n", countA);

    // Test sort
    sort(&list1, 1);
    printf("Sorted List 1 in ascending order: ");
    printList(list1);
    printf("\n");

    // Test shrinkList
    shrinkList(&list1, 2);
    printf("List 1 after shrinking: ");
    printList(list1);
    printf("\n");

    // Test compressList
    compressList(&list1);
    printf("List 1 after compression: ");
    printList(list1);
    printf("\n");

    // Test dealocateList
    dealocateList(&list1);
    printf("List 1 after deallocation: ");
    printList(list1);
    printf("\n");

    return 0;
}
