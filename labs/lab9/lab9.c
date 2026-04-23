#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct PatientInfo{
    int ID;
    char name[100];
    int severity;
    struct PatientInfo *next;
} Patient;

typedef struct List{
    Patient* head;
}Header;

void DisplayQueue(Header* Queue);
void TreatPatient(Header* Queue);
void DeleteAll(Header* Queue);

bool InsertFirst(Header* Queue, int PatientID, char PatientName[100], int Severity);
bool InsertInList(Header* Queue, int PatientID, char PatientName[100], int Severity);
bool RemovePatient(Header* Queue, int PatientID);

int main(void){
    char command;
    int inputID;
    char inputName[100];
    int inputseverity;
    bool ProgramisRunning = true;
    Header Patientlist; 
    Patientlist.head = NULL;
    
    while(ProgramisRunning){
        scanf("%c", &command); //&inputID, inputName, &inputseverity
        if(command == 'Q'){
            DeleteAll(&Patientlist);
            break;
        }
        if(command == 'A'){
            scanf("%d %s %d", &inputID, inputName, &inputseverity);
            InsertInList(&Patientlist, inputID, inputName, inputseverity);
        } 
        if(command == 'T'){
            TreatPatient(&Patientlist);
        } 
        if(command == 'R'){
            scanf("%d", &inputID);
            RemovePatient(&Patientlist, inputID);
        } 
        if(command == 'D'){
            DisplayQueue(&Patientlist);
        }
    }
    return 0;
}

Patient* CreatePatient(int PatientID, char PatientName[100], int Severity){
    Patient* newPatient = (Patient*) malloc(sizeof(Patient));
    newPatient->ID = PatientID;
    strcpy(newPatient->name, PatientName);
    newPatient->severity = Severity;
    newPatient->next = NULL;
    printf("Patient %d Added.\n", newPatient->ID);
    return newPatient;
}

bool InsertFirst(Header* Queue, int PatientID, char PatientName[100], int Severity){
    Patient* temp = CreatePatient(PatientID, PatientName, Severity);
    if(temp == NULL){
        return false;
    }
    temp->next = Queue->head;
    Queue->head = temp;
    return true;
}

bool InsertBack(Header* Queue, int PatientID, char PatientName[100], int Severity){
    if(Queue->head == NULL){
        return InsertFirst(Queue, PatientID, PatientName, Severity);
    }

    Patient* CurrentPatient = Queue->head;
    while(CurrentPatient->next != NULL){
        CurrentPatient = CurrentPatient->next;
    }

    CurrentPatient->next = CreatePatient(PatientID, PatientName, Severity);
    if(CurrentPatient->next == NULL){
        return false;
    }
    return true;
}

bool InsertInList(Header* Queue, int PatientID, char PatientName[100], int Severity){
    Patient* CurrentPatient = Queue->head;
     
    if(Queue->head == NULL){
        return InsertFirst(Queue, PatientID, PatientName, Severity); // If list empty
    }

    while(CurrentPatient != NULL){
        if(CurrentPatient->ID == PatientID){
            printf("Error: Patient %d already exists.\n", PatientID);
            return false;
        }
        CurrentPatient = CurrentPatient->next;
    }

    CurrentPatient = Queue->head;
  
    if(Severity > Queue->head->severity){
        return InsertFirst(Queue, PatientID, PatientName, Severity); 
    }

    while(CurrentPatient->next != NULL && Severity <= CurrentPatient->next->severity){
        CurrentPatient = CurrentPatient->next;
    }

    Patient *NewPatient = CreatePatient(PatientID, PatientName, Severity);
    if(NewPatient == NULL){
        return false;
    }

    NewPatient->next = CurrentPatient->next;
    CurrentPatient->next = NewPatient;

    return true;
}

void DisplayQueue(Header* Queue){
    Patient* currentPatient = Queue->head;
    // Display name and severity level
    if(currentPatient == NULL){
        printf("Queue is empty.\n");
    }
    while(currentPatient != NULL){
        printf("%s %d\n", currentPatient->name, currentPatient->severity);
        currentPatient = currentPatient->next;
    }
}

void TreatPatient(Header* Queue){
    if(Queue->head == NULL){
        printf("Queue is empty.\n");
        return;
    }

    printf("Patient %d Treated.\n", Queue->head->ID);
    Patient* newHeader = Queue->head->next;
    free(Queue->head);
    Queue->head = newHeader;
}

bool RemovePatient(Header* Queue, int PatientID){
    if(Queue->head == NULL){
        printf("Error: Patient %d not found.\n", PatientID);
        return false;
    }
    if(Queue->head->ID == PatientID){
        printf("Patient %d Removed.\n", Queue->head->ID);
        Patient* newHeader = Queue->head->next;
        free(Queue->head);
        Queue->head = newHeader;
        return true;
    }

    Patient* CurrentPatient = Queue->head;
    while(CurrentPatient->next != NULL && CurrentPatient->next->ID != PatientID){
        CurrentPatient = CurrentPatient->next;
    }

    if(CurrentPatient->next != NULL){
        Patient* temp = CurrentPatient->next;
        CurrentPatient->next = temp->next;
        printf("Patient %d Removed.\n", temp->ID);
        free(temp);
        return true;
    }

    printf("Error: Patient %d not found.\n", PatientID);
    return false;
}

void DeleteAll(Header* Queue){
    while(Queue->head != NULL){
        if(Queue->head == NULL){
            return;
        }
        Patient* newHeader = Queue->head->next;
        free(Queue->head);
        Queue->head = newHeader;
    }
    Queue->head = NULL;
}
