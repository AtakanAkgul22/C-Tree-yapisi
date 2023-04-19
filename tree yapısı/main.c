#include <stdio.h>
#include <stdlib.h>

typedef struct agac{
    int data;
    struct agac* sol;
    struct agac* sag;
}agac;

agac* ekle(agac* root,int data){
    if(root==NULL){
        root=(agac*)malloc(sizeof(agac));
        root->data=data;
        root->sol=NULL;
        root->sag=NULL;
        return root;
    }
    if(root->data < data){
        root->sag=ekle(root->sag,data);
        return root;}
    root->sol=ekle(root->sol,data);
    return root;
}
void dolas (agac* root){
    if(root==NULL)
        return;
    dolas(root->sag);
    printf("%d ",root->data);
    dolas(root->sol);
}

int bul(agac* root,int aranan){
    if(root==NULL)
        return -1;
    if(root->data==aranan)
        return 1;
    if(bul(root->sag,aranan)==1)
        return 1;
    if(bul(root->sol,aranan)==1)
        return 1;
    return -1;
}
int max(agac* root){
    while(root->sag!=NULL)
        root=root->sag;
    return root->data;
}
int min(agac* root){
    while(root->sol!=NULL)
        root=root->sol;
    return root->data;
}

agac* silinecek(agac* root,int sil){
    if(root==NULL)
        return NULL;
    if(root->data==sil){
        if(root->sag==NULL && root->sol==NULL){
            return NULL;
        }
        if(root->sag!=NULL){
            root->data=min(root->sag);
            root->sag=silinecek(root->sag,min(root->sag));
            return root;
        }
        root->data=max(root->sol);
        root->sol=silinecek(root->sol,max(root->sol));
        return root;
    }
    if(root->data < sil){
        root->sag=silinecek(root->sag,sil);
        return root;
    }
    root->sol=silinecek(root->sol,sil);
    return root;

    }


int main()
{
    agac* agac=NULL;
    agac=ekle(agac,12);
    agac=ekle(agac,200);
    agac=ekle(agac,190);
    agac=ekle(agac,213);
    agac=ekle(agac,56);
    agac=ekle(agac,24);
    agac=ekle(agac,18);
    agac=ekle(agac,27);
    agac=ekle(agac,28);
    dolas(agac);
    printf("arama sonucu: %d",bul(agac,18));
    printf("arama sonucu: %d",bul(agac,999));
    printf("max= %d min=%d",max(agac),min(agac));
    printf("\n");
    silinecek(agac,12);
    silinecek(agac,200);
    silinecek(agac,190);
    silinecek(agac,999);
    dolas(agac);
    printf("max= %d min=%d",max(agac),min(agac));

    return 0;
}
