#include<stdio.h>
#include <stdlib.h>
typedef  struct cellule* Pcellule;

typedef struct cellule
{
    int value;
    Pcellule next;
};

/* ------------------------------------function to create a list--------------------------------------*/

void create_liste(Pcellule L)
{
    Pcellule element,suite;
    int data, i, n;
    printf("Enter the length of your list\n");
    scanf("%d",&n);
    printf("Enter the first element of your list:\n");
    scanf("%d",&data);
    element = L;
    element->value=data;
    element->next=NULL;
    for (i=2;i<=n; i++)
    {
        printf("Enter the %dth element of list \n",i);
        scanf("%d",&data);
        suite = malloc(sizeof(Pcellule));
        suite->value = data;
        suite->next = NULL;
        element->next = suite;
        element = suite;
    }
}
/* ------------------------------------function to add an element at the head of the  the list--------------------------------------*/

Pcellule add_element_head(Pcellule L)
{
    int data;
    printf("\nEnter the element to add at the head of the list\n");
    scanf("%d",&data);
    Pcellule head;
    head = malloc(sizeof(Pcellule));
    head->value = data;
    head->next = L;
    return head;
}

/*-------------------------------------function to print the list---------------------------------------------------------*/
void print_list(Pcellule L)
{
    Pcellule p= L;
    //printf("The list:");
    while(p!=NULL){
        printf("%d\t",p->value);
        p=p->next;
    }
    //printf("NULL");
}
/*----------------------------------------------function to add element at the tail of the list--------------------------------------------------*/
void add_element_tail(Pcellule L)
{
    Pcellule element, liste;
    liste = L;
    int data;
    printf("\nEnter the element to add at the tail of the list\n");
    scanf("%d",&data);
    element = malloc(sizeof(Pcellule));
    element->value = data;
    element->next = NULL;
    if (liste!=NULL)
    {
        while(liste->next!=NULL)
        {
            liste = liste->next;
        }
        liste->next = element;
    }
}

/*----------------------------------------------------------function to sort the list------------------------------------------------------------------*/
Pcellule Sort(Pcellule L)
{
    Pcellule liste, element;
    liste = L;
    int tmp;
    if (liste!=NULL){
        while (liste->next!=NULL)
        {
            element = liste->next;
            while(element!=NULL)
            {
                if(element->value < liste->value)
                {
                    tmp = element->value;
                    element->value = liste->value;
                    liste->value = tmp;
                }
                element = element->next;
            }
            liste = liste->next;
        }
    }
    return L;
}


/*------------------------------------------------------------function to delete a element to the list ---------------------------------------------*/

void Delete_element(Pcellule L)
{
    Pcellule element, liste ;
    int data, find = 0;
    printf("\nEnter the element that you want to delete from the list\n");
    scanf("%d",&data);
    liste = L;
    
        while(liste->next!=NULL)
        {
            liste = L->next;
            if(liste->value == data)
            {
                find = 1;
                L->next = liste->next;
                free(liste);
            }
            else
            {
                L = L->next;
            }
        }
        if(!find)
        {
            printf("\n\nThe element is not in list...!!\n");
        }

}
/*----------------------------------------------------------Function to pop the last element from the list*-------------------------------------*/


Pcellule Pop(Pcellule L)
{
    Pcellule element, liste ;
    liste = L;
        while(liste->next->next!=NULL)
        {
            liste = liste->next;
        }
        if(liste->next!=NULL)
        {
            element = liste->next;

            liste->next = liste->next->next;
            free(element);

        }
    return L;

}

/*------------------------------------------------------function to delete the duplicates from the list *--------------------------------------------*/



void Delete_duplicate(Pcellule L)
{
    Pcellule liste , element;
    if (L != NULL)
    {
        for(liste = L; liste->next != NULL; liste = liste->next)
        {
            if(liste->value == liste->next->value)
            {
                element = liste->next;
                liste->next = liste->next->next;
                free(element);
            }
        }
    }
}

/*-----------------------------------------------------------function to merge two lists -------------------------------------*/


Pcellule merge_lists(Pcellule L, Pcellule B)
{
    Pcellule liste, A = NULL, copyL, copyB, element;
    copyL = L;
    copyB = B;
    while((copyL != NULL) &&  (copyB != NULL))
    {
        element = malloc(sizeof(Pcellule));
        if(copyL->value < copyB->value)
        {
            element->value = copyL->value;
            element->next = NULL;
            copyL = copyL->next;
        }
        else if(copyL->value == copyB->value)
        {
            element->value = copyL->value;
            element->next = NULL;
            copyL = copyL->next;
            copyB = copyB->next;
        }
        else
        {
            element->value = copyB->value;
            element->next = NULL;
            copyB = copyB->next;
        }
        if (A == NULL)
        {
            A = element;
            liste = A;
        }
        else
        {
            A->next = element;
            A = element;
        }

    }
    if(copyL==NULL)
        A->next = copyB;
    else
        A->next = copyL;
    return liste;
}




/*-------------------------------------function to concate--------------------------------------------------*/

Pcellule concat(Pcellule a, Pcellule b)
{
    Pcellule liste,element = a;
    while(element->next!=NULL)
    {
        element = element->next;
    }
    element->next = b;
    return a;


}




/*-----------------------------------------------function to inverse the list-------------------------------------------------*/

Pcellule inverse(Pcellule L)
{
    Pcellule liste = L, q=NULL,tmp;
    while(liste!=NULL)
     {
        tmp = liste->next;
        liste->next = q;
        q = liste;
        liste=tmp;

    }
    return q;
}

/*--------------------------------------------------------------------function to calculate the length of the list---------------------------------------------------*/

int length(Pcellule l)
{
    Pcellule liste = l;
    int a=0;
    for (liste = l; liste != NULL; liste = liste->next)
        a+=1;
    return a;

}

/*---------------------------------------------------------------function to check if a list is palindrome-------------------------------------------*/


int is_palindrome(Pcellule L)
{
    Pcellule liste = L,tmp, p = NULL;
    int n = length(liste),i;
    for(i=0; i<n/2; i++)
    {
        tmp = liste;
        while(tmp->next != p)
        {
            tmp = tmp->next;
        }
        if(tmp->value != liste->value)
            return 0;
        p = tmp;
        liste = liste->next;
    }

    return 1;
}

/*----------------------------------------------menu function---------------------------------------*/

int menu()
{
    int m;
    printf("\n\n\n-----------------------MENU----------------------------\n\n");
    printf("1.Create a linked list of integer\n");
    printf("2.Add a element at the head of the list \n");
    printf("3.Add element at the tail of the list \n");
    printf("4.Sort the list\n");
    printf("5.Remove a element to the list \n");
    printf("6.Delete the duplilcates\n");
    printf("7.Delete the last element to the list\n");
    printf("8.Merge two lists\n");
    printf("9.Inverse the list\n");
    printf("10.Check if the list current is a  palindrome\n");
    printf("11.Quit\n");
    printf("\n\nEnter just the number\t:");
    scanf("%d",&m);
    while(m>11)
    {
        printf("\n\nInvalid option..!!!");
        m = menu();
    }
    return m;
}




/* -------------------------------------------------------------------THE MAIN -------------------------------------------------------------*/


int main()
{
    Pcellule L=NULL,A=NULL,B=NULL;
    int a = 1,b,v;

    b = menu();
    while(b!=1)
    {
            if(b==11)
                return 0;
            printf("\n\nPlease create the list first\n\n");
            b = menu();
    }
     while(a==1)
    {

        switch(b)
        {
            case 1:
                L = malloc(sizeof(Pcellule));
                create_liste(L);
                printf("\n\nThe list\n");
                print_list(L);
                break;
            case 2:
                    L= add_element_head(L);
                    printf("\n\nList next adding element at the head:\n");
                    print_list(L);

                break;
            case 3:
                    add_element_tail(L);
                    printf("\n\nList next adding element at the tail:\n");
                    print_list(L);
                break;
            case 4:
                    Sort(L);
                    printf("\n\nSorted list:\n");
                    print_list(L);
                break;
            case 5:
                    L = Delete_element(L);
                    printf("\n\nnext removing the element from the list:\n");
                    print_list(L);
                break;
            case 6:
                    L = Sort(L);
                    Delete_duplicate(L);
                    printf("\n\nList without the duplicate element:\n");
                    print_list(L);
                break;
            case 7:
                    L = Pop(L);
                    printf("\n\nnext removing the last element from the list:\n");
                    print_list(L);
                break;
            case 8:
                    B = malloc(sizeof(Pcellule));
                    A = malloc(sizeof(Pcellule));
                    printf("\n\nCreate the second list:\n");
                    create_liste(B);
                    L = Sort(L);
                    B = Sort(B);
                    A = merge_lists(L,B);
                    printf("\n\nThe merged list:\n");
                    print_list(A);
                    L = A;
                break;
            case 9:
                    L = inverse(L);
                    printf("\n\nThe list next inversing:\n");
                    print_list(L);
                break;
            case 10:
                    v = is_palindrome(L);
                    if (v==1)
                        printf("The list is a palindrome");
                    else
                        printf("The list is not a palindrome");
                break;
            default:
                printf("\nThanks to visit us...!");
                return 0;

        }
        b = menu();
        a = 1;


    }


    return 0;
}


