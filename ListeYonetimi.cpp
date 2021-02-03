#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node {
	int veri;
	struct node * next;
};
struct node * head;
int say = 0;
void sayguncelle(){
	say = 0;
	struct node * temp;
	temp = head;
	if(temp != NULL){
		say+=1;
		while(temp->next != NULL){
			say+=1;
			temp = temp->next;
		}
	}
}
struct node * olustur(int n){
	struct node * temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->veri = n;
	temp->next = NULL;
	return temp;
}
void listeYazdir(char islem){
	struct node * temp;
	int kacinci = 0;
	if(islem == 'e' || islem == 'E'){
		printf("%d) Basa ekle\n",0);	
	}
	if(head != NULL){
		temp = head;
		kacinci+=1;
		printf("%d) %d\n",kacinci,temp->veri);
		while(temp->next != NULL){
			temp = temp->next;
			kacinci+=1;
			printf("%d) %d\n",kacinci,temp->veri);
		}
	}
}
void sonEkle(int n){
	if(head == NULL){
		head = olustur(n);
	}else{
		struct node * temp;
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = olustur(n);
	}
}
void ekle(int sira,int deger){
	if(sira < 0 || sira > say){
		printf("Sira degerini kontrol ediniz");
	}else{
		struct node * tmp;
		tmp = head;
		struct node * eklenecek;
		eklenecek = olustur(deger);
		if(sira == 0){
			eklenecek->next = head;
			head = eklenecek;
		}else if(sira < say){
			for(int x=1;x<sira;x++){
				tmp = tmp->next;
			}
			eklenecek->next = tmp->next;
			tmp->next = eklenecek;
		}else if(sira == say){
			sonEkle(deger);
		}
	}
	sayguncelle();
}
void guncelle(int sira,int deger){
	if(sira < 0 || sira > say){
		printf("Sira degerini kontrol ediniz");
	}else{
		struct node * tmp;
		tmp = head;
		if(sira == 0){
			head->veri = deger;
		}else if(sira <= say){
			for(int x=1;x<sira;x++){
				tmp = tmp->next;
			}
			tmp->veri = deger;
		}	
}
sayguncelle();
}
void sil(int sira){
	if(sira < 0 || sira > say){
		printf("Sira degerini kontrol ediniz");
	}else{
		struct node * tmp;
		struct node * prev;
		tmp = head;
		if(sira == 1){
		head = tmp->next;
		}else if(sira < say){
			for(int x=1;x<sira;x++){
				prev = tmp;
				tmp = tmp->next;
			}
			prev->next = tmp->next;
		}else if(sira == say){
				for(int x=1;x<say;x++){
				prev = tmp;
				tmp = tmp->next;
			}
			prev->next = NULL;
		}
	}
	sayguncelle();
}
int main(){
	char dvm;
	char islem;
	int eklenecek;
	printf("Eklenecek ilk degeri giriniz : ");
	scanf("%d",&eklenecek);
	ekle(0,eklenecek);
	do{
	printf("Listede %d adet veri mevcut\n",say);
	dvm = 'h';
	do{
		printf("Islem Sec;\nEkle E-e\nSil S-s\nGuncelle G-g\nListele L-l\nSonlandir B-b\nTemizle T-t\nSecim: ");
		islem = getch();
		printf("\n");
	}while(islem != 'e' && islem != 'E' && islem != 's' && islem != 'S' && islem != 'g' && islem != 'G' && islem != 'b' && islem != 'B' && islem != 'l' && islem != 'L' && islem != 't' && islem != 'T');
	if(islem == 'e' || islem == 'E'){
	int kacincisira;
	
	do{
		listeYazdir('e');
		printf("Kacinci siradan sonraya eklemek istersiniz ? ");
		scanf("%d",&kacincisira);
	}while(kacincisira < 0 || kacincisira > say);
		printf("Hangi degeri eklemek istersiniz : ");
		scanf("%d",&eklenecek);
		ekle(kacincisira,eklenecek);
	}
	if(islem == 'g' || islem == 'G'){
	int kacincisira;
	
	do{
		listeYazdir('n');
		printf("Hangi sirayi guncellemek istersiniz ? ");
		scanf("%d",&kacincisira);
	}while(kacincisira < 0 || kacincisira > say);
		printf("Hangi degere guncellemek istersiniz : ");
		scanf("%d",&eklenecek);
		guncelle(kacincisira,eklenecek);
	}
	if(islem == 's' || islem == 'S'){
	int kacincisira;
	
	do{
		listeYazdir('n');
		printf("Hangi sirayi silmek istersiniz ? ");
		scanf("%d",&kacincisira);
	}while(kacincisira < 0 || kacincisira > say);
		sil(kacincisira);
	}
	if(islem == 'B' || islem == 'b'){
		printf("\nListe\n");
		listeYazdir('l');
		break;
		dvm = 'e';
	}
	if(islem == 'L' || islem == 'l'){
		printf("\nListe\n");
		listeYazdir('l');
	}
	if(islem == 't' || islem == 'T'){
		printf("\nListe\n");
		system("cls");
	}
	}while(dvm != 'e' && dvm != 'E');
	
system("pause");
return 0;
}
