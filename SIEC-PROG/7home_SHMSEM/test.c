#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 0x1234

int main() {
    int shmid;
    int *counter;

    // 1. Utwórz albo pobierz segment pamięci
    shmid = shmget(
        SHM_KEY,
        sizeof(int),
        IPC_CREAT | 0666
    );

    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // 2. Podłącz segment do przestrzeni adresowej
    counter = (int *)shmat(shmid, NULL, 0);
    if (counter == (void *)-1) {
        perror("shmat");
        return 1;
    }

    // 3. Zwiększ licznik
    (*counter)++;

    // 4. Wypisz aktualną wartość
    printf("Licznik = %d\n", *counter);

    // 5. Odłącz pamięć
    shmdt(counter);

    return 0;
}
