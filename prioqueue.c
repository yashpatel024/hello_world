//yash

//16bit024

#include <stdio.h>
#include <Math.h>
#define iSize 10
int iPriority;
int iapQueue[iSize];

void fInsertion(int ,int);
void fDeletion(int);
//void fDisplay();
void main(){

    printf("Enter the numbers of priority=");
    scanf("%d",&iPriority);
    int iIndex1,iIndex2;
    int iFront[iPriority];
    int iRear[iPriority];


    for(iIndex1=0; iIndex1<iPriority; iIndex1++){
        iFront[iIndex1]=iRear[iIndex1]=(iSize/iPriority)*(iIndex1)-1;
    }

    int iChoice;
    int iFlow=0;
    int iPrio,iEle;
    while(iFlow==0){
        printf("\n1 - Insert an element into queue");
        printf("\n2 - Delete an element from queue");
        printf("\n4 - Exit");
        printf("\nChoice=");
        scanf("%d",&iChoice);
                    int iPtr=0;
            int iIndex2=0;
            int iPtr2=0;
            int iIn;
        switch(iChoice){

        case 1:

            printf("\nEnter priority = ");
            scanf("%d",&iPrio);
            if(iRear[iPrio-1]==(iSize/iPriority)*(iPrio)-1){
                    printf("Overflow");
                    break;
            }else{
                printf("\nEnter Element = ");
                scanf("%d",&iEle);
                if(iFront[iPrio-1]==iRear[iPrio-1]==(iSize/iPriority)*(iPrio-1)-1){
                    iFront[iPrio-1]++;
                    iRear[iPrio-1]++;
                }else{
                    iRear[iPrio-1]++;
                }
                int iPtr=iRear[iPrio-1];
                fInsertion(iEle,iPtr);
                break;
            }

        case 2:
            for(iIndex1=0; iIndex1<iPriority; iIndex1++){
                if(iFront[iIndex1] == (iSize/iPriority)*(iIndex1)-1){
                    printf("\nOverflow");
                    break;
                }
                if(iFront[iIndex1]==iSize/iPriority*iIndex1-1 ){
                    iIndex1++;
                    iPtr2=iIndex1+1;
                    iPtr=iFront[iIndex1+1];
                }

            }
            fDeletion(iPtr);
            if(iPtr!=iRear[iIndex2-1]){
                iPtr++;
                iFront[iIndex2-1]++;
            }else{
                iPtr==-1;
                iFront[iIndex2-1]=iRear[iIndex2-1]=iSize/iPriority*(iIndex2-1)-1;
            }
            break;
        case 3:
            iIn=0;
            for(iIndex1=0; iIndex1<iPriority; iIndex1++){
                for(iIndex2=0; iIndex2<iFront[iIndex1]; iIndex2++){
                    printf(" %d ",iapQueue[iIn]);
                    iIn++;
                }
                printf("\n");
            }

        case 4:
            iFlow=1;
            break;
        }
    }
}

void fInsertion(int iEle, int iPtr){
    iapQueue[iPtr]=iEle;
}

void fDeletion(int iPtr){
    printf("%d",iapQueue[iPtr]);
}






















