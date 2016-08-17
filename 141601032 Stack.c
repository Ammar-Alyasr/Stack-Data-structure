/*
	* Ammar Ahmed Abdo SAEED 141601032
	* Bu program Veri yapuilari ders odevi icin yapilmistir..
	*Mugla Sitki Kocman Universitesi Tknoloji Fakultesi Bilisim Sistemleri Muhendisligi ..
	*09.12.2015 ....
	*yayma haki yukardaki isme aittir ...
*/

/*
	* programin yapacagi islem su :
	Elimizde 15 büyüklügünde 2 adet yigit (stack) olsun.
	Klavyeden karisik girilen 15 adet integer tipinde sayinin
	A yigitinda küçükten büyüge siralanmis olarak saklanmasi gerekiyor. 
	Bunun için B yigiti geçis islemleri için tampon olarak kullanilacak
    (Eger o anda girilen sayi A yigitindaki sayilardan küçükse A yigitindaki sayilarin B’ye tasinmasi gerekiyor).   
			- Her sayi girisinden sonra yigitlarin durumu ekranda görüntülenecek.  
			- Sayi girisi bittikten tüm sayilarin A’da küçükten büyüge siralanmis olmasi gerekiyor.  
			- Sonra büyükten küçüge siralama yapilmak isteyip istenmedigi sorulacak. 
			Eger “evet” ise tüm sayilar B’ye tasindiginda siralama islemi gerçeklesmis olacak. 
*/


#include<stdio.h>
#include<stdlib.h>


struct Stack
{
	int icerik[15];
	int top;
	int sayac;
	
};

void great(struct Stack * a)
{
	a->top = -1;   
	a->sayac = 0;
		
}

void push(struct Stack * a,  int eklenecek) 
{

	a->top++;
	a->sayac++;
	
	
	a->icerik[a->top] = eklenecek;	
}

int pop(struct Stack *a )   
{
	int m;
	m= a->icerik[a->top];
	a->top--;
	a->sayac--;
    return (m);
    
}

void yazdir(struct Stack *l);

void anaMenu();

int main()
{
	
	
	anaMenu();
	
	return 0;
}


void anaMenu(){
	
	system("cls");
	int secenek;
	
	printf("\n 1-Siralama\n 2-Cikis\n");
	scanf("%d:",&secenek);
	
	if (secenek==1)
	{

	
	int str;

	struct Stack A;
	struct Stack B;
	great(&A);
	great(&B);
	
	
	int i,d,z;
	for(i=0;i<15;i++)
	{
		printf("\n%d. sayi gir : \n",i+1);
		scanf("%d",&str);

		while(1){
		
		if(A.sayac==0){
			push(&A, str);
			
			printf("\n>>>A Stack \n");
			yazdir(&A); 
			printf("\n>>>B Stack breakte \n");
			yazdir(&B);
			break;
		}
		
		else {
		
			if (str<A.icerik[A.top]){
			
				
				push(&B, pop(&A));
				printf("\n>>>A Stack \n");
				yazdir(&A); 
				printf("\n>>>B Stack \n");
				yazdir(&B);
			
			}
		
			else {
	
				push(&A, str); 
				printf("\n>>>A Stack \n");
				yazdir(&A);
				printf("\n>>>B Stack \n");
				yazdir(&B);
				
				//yazdir(&B);
				break;
			
			
				}
			}
			
			
		}
		
		while (B.sayac!=0){
			push(&A, pop(&B));	
			
		}
			
	}
	printf("\n>>>A Stack Son hali \n");
	yazdir(&A);
	

	
	
	char secim;
	printf("Ters yazilsin mi 'e' ? \n");
	scanf("%s",&secim);
	
	if (secim=='e'){
		printf("Ters Yazildi \n");
		while(A.sayac!=0){
			push(&B, pop(&A));
			
		}
		yazdir(&B);
			
			
	} 
	
	else {
		anaMenu();
		system("cls");
	}
	
}

	else system("PAUSE");
}

void yazdir(struct Stack *l)
{

	for(int i=0; i<l->sayac;i++){
		printf("%d\n",l->icerik[i]);
	}
	
}
