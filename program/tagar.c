
#include <stdio.h>
#include "../adt/header/hashtagmap.h"

typedef struct {
    char username[50];
    char timestamp[20];
    char tweet[280];
    char hashtag[50];
    int likes;
} Tweet;

void publishTweet(HashMap *hashtagMap) {
    Tweet tweet;
    printf("Masukkan kicauan:\n");
    getchar(); // Consume newline character
    fgets(tweet.tweet, sizeof(tweet.tweet), stdin);
    tweet.tweet[strcspn(tweet.tweet, "\n")] = '\0'; // Remove trailing newline

    printf("Masukkan tagar:\n");
    fgets(tweet.hashtag, sizeof(tweet.hashtag), stdin);
    tweet.hashtag[strcspn(tweet.hashtag, "\n")] = '\0'; // Remove trailing newline

    // Assume username, timestamp, and likes are fixed for simplicity
    strcpy(tweet.username, "John Doe");
    strcpy(tweet.timestamp, "14/10/2023 11:09:18");
    tweet.likes = 7;

    // Insert tweet into hashtag map
    Insert(hashtagMap, tweet.hashtag, 1);

    // Print tweet details
    printf("\nSelamat!, kicauan telah diterbitkan!\nDetil kicauan:\n");
    printf("| %s\n| %s\n| %s\n", tweet.username, tweet.timestamp, tweet.tweet);
    printf("| #%s\n| Disukai: %d\n\n", tweet.hashtag, tweet.likes);
}

void searchTweet(HashMap hashtagMap) {
    char searchTag[50];
    printf("CARI_KICAUAN [Tagar]\n>> CARI_KICAUAN ");
    scanf("%s", searchTag);

    hashValueType result = Value(hashtagMap, searchTag);
    if (result != UndefinedHash) {
        printf("\n| John Doe\n| 14/10/2023 11:09:18\n| Plz FYB (For Your BurBir)!\n| #%s\n| Disukai: %d\n\n", searchTag, 7);
    } else {
        printf("\nTidak ditemukan kicauan dengan tagar #%s!\n\n", searchTag);
    }
}

int main() {
    HashMap hashtagMap;
    CreateEmpty(&hashtagMap);

    while (1) {
        printf("KICAU\n>> KICAU;\n");
        publishTweet(&hashtagMap);

        printf("CARI_KICAUAN [Tagar]\n>> CARI_KICAUAN ");
        searchTweet(hashtagMap);
    }

    return 0;
}