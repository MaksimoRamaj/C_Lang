#include <stdio.h>
#include <string.h>
#include <conio.h>

struct artikulli{
	char id[20];
	char kategoria[100];
	char emertimi[200];
	int cmimi;
	int sasia;
} art[200];

struct klienti{
	char klient_id[20];
	char emri[50];
	char mbiemri[50];
	char tel[15];
    int shpeshtesia;
    float total;
} k[200];

struct shitje{
	int id_fatura;
	char klient_id[20];	
	char dt_shitjes[15];
	int vlera;
	
	struct shitje_detaje{
		char id_art[20];
		int sasia;
		int cmimi;
		int vlera;
	}sd[10];
} s[200];

struct furnizim{
	char id_furnizmit[20];
	char dt_furnizmit[15];
	int vlera;
	
	struct furnizim_detaje{
		char id_art[20];
		int sasia;
		int cmimi;
		int vlera;
	}fd[10];
} f[200];

void menu()
{
  printf("\n=============================\n");
  printf("\n   Detyre   Kursi");
  printf("\n 1 - Regjistrim artikulli ");
  printf("\n 2 - Regjistrim klienti ");
  printf("\n 3 - Furnizimi ");
  printf("\n 4 - Shitje ");
  printf("\n 5 - Gjendja magazine ");
  printf("\n 6 - Klientet qe blejne me shume ");
  printf("\n 7 - Klientet qe blejne me shpesh ");
  printf("\n 8 - Kerkim artikulli sipas kodit ");
  printf("\n S/s - Save ");
  printf("\n L/l - Lexo ");
  printf("\n d - Dalje");
  printf("\n-----------------------------");
  printf("\n Zgjedhja : ");
}

int nr_art=0,nr_klient=1,nr_sh=0,nr_furnizimi=0;
int id_fatura=1;
void lexo();
void save();

void shitje(){
    //char tmp[20];
    char tmp2[20];char tmp[20];int numri2;
        printf("\nJepni id e klientit : ");
		scanf("%s",tmp2); fflush(stdin);
		strcpy(tmp,tmp2); fflush(stdin);
    //kam perdorur 2 var tmp sepse nuk po ndodhte mbivendosja gjate ciklit 2
    // scanf("%s",tmp);
    //kontrollojm nese ekziston si klient 
    int kushti = 0; //kushti 0 dmth negative
    for(int i=0;i<nr_klient;i++){
        if(strcmp(k[i].klient_id,tmp)==0){
            kushti = 1;
            numri2 = i;
            break;
        }
    }

    if(kushti==0){
        printf("\nKlienti nuk ekziston! ");
        return;
    }
    /*printf("\nVendos id e fatures: ");char tmp3[20];
    scanf("%s",tmp3);
    strcpy(s[nr_sh].id_fatura,tmp3);*/

    s[nr_sh].id_fatura=id_fatura++;
    fflush(stdin);
    printf("\nVendosni daten e shitjes ne formatin (dita/muaj/viti) ");
    gets(s[nr_sh].dt_shitjes);
    fflush(stdin);
    //llogarisim vleren totale te shitjes
    //char tmp2[20];
    char c;
    int d=0;
    float vlera=0;float sasia=0;
    
	do{
		printf("\nJepni id e artikullit : ");
		scanf("%s",tmp);
		fflush(stdin);
		for(int i=0;i<nr_art; i++)
			if(strcmp(tmp, art[i].id)==0){
				printf ("Jepni sasine e \"%s\": ",art[i].emertimi);
				scanf("%d", &s->sd[d].sasia);fflush(stdin);
				
				if(s->sd[d].sasia>art[i].sasia){
					printf("\n Nuk ka sasi te mjaftueshme.");
					break;
				}
				//marrim cmimin e artikullit
				s->sd[d].cmimi=art[i].cmimi;
                //marrim id e artikullit e kalojme ne strukture
				strcpy(s->sd[d].id_art,tmp);fflush(stdin);
                //gjejm vleren e sasise se shitur dhe e printoj
				s->sd[d].vlera = s->sd[d].cmimi * s->sd[d].sasia;
				art[i].sasia = art[i].sasia - s->sd[d].sasia;
				vlera+=s->sd[d].vlera;
				d++;
			}
		
		printf("\n Deshironi te shtoni artikull tjeter (P/J):");
		scanf("%c", &c);fflush(stdin);
		if (c=='J'||c=='j'){
            printf("\nVlera totale e shitjes = %.2f leke",vlera);
            printf("\nId e fatures: %d",s[nr_sh].id_fatura);
            //llogaris sa shpesh ble dhe totalin gjate gjithe historikut
            k[numri2].shpeshtesia=k[numri2].shpeshtesia+1;
            k[numri2].total = k[numri2].total + vlera;
			break;
        }
	}while(1);
	nr_sh++;
	s[nr_sh];
}

void regjistro_artikull(){
    char tmp[20];
	printf("\n===Regjistrim artikulli!===");
	printf("\nJepni ID: ");
	
	scanf("%s",tmp);
	//kontrollojm nese eshte i regjistruar
	for(int i=0; i<nr_art;i++){
		if (strcmp(art[i].id,tmp)==0){
			printf("\nKjo ID eshte regjistruar me pare.");
			return;
		}
	}
	//art me index nr_art merr vleren e tmp
	
    strcpy(art[nr_art].id,tmp);
	fflush(stdin);

	printf("\nJepni Emertimin: ");
	gets(art[nr_art].emertimi);
    fflush(stdin);

    printf("\nJepni cmimin: ");
	scanf("%d",&art[nr_art].cmimi);
	fflush(stdin);

	printf("\nJepni Kategorine: ");
	gets(art[nr_art].kategoria);
	fflush(stdin);
	art[nr_art].sasia=0;
	nr_art++;
}

void regjistro_klient(){

    char tmp[20];

    printf("\n===Regjistrim klienti!=== ");
    printf("\nVendos id e klientit: ");

    scanf("%s",tmp);

    for(int i=0;i<nr_klient;i++){
        if(strcmp(k[i].klient_id,tmp)==0){
            printf("\nKy klient eshte regjistruar me pare! ");
            return ;
        }
    }

    strcpy(k[nr_klient].klient_id,tmp);
    //kalimi i id ne strukture
    fflush(stdin);
    printf("\nVendosni emrin e klientit: ");
    gets(k[nr_klient].emri);

    printf("\nVendsoni mbiemrin e klientit: ");
    gets(k[nr_klient].mbiemri);

    printf("\nVendosni numrin e tel: ");
    gets(k[nr_klient].tel);
    
    //kalimi i id ne strukture
    nr_klient++;
    
}

void shto_furnizim(){
    char tmp[20];

    printf("\nVendosni id e furnizimt: ");
    scanf("%s",tmp);

    /*kontrollojm nese ekziston nje furnizim
    i meparshem me te njejtin id*/

    for(int i=0;i<nr_furnizimi;i++){
        if(strcmp(f[i].id_furnizmit,tmp)==0){
            printf("\nKy furnizim ekziston!");
            return;
        }  
    }

    //nese nuk u gjet nje furnizim me te njejtin id

    strcpy(f[nr_furnizimi].id_furnizmit,tmp);
    fflush(stdin);
    printf("\nVendosni daten e furnizimit ne formatin (dita/muaj/viti): ");
    gets(f[nr_furnizimi].dt_furnizmit);
    fflush(stdin);
    //llogarisim vleren totale te furnizimit
    
    char c;
    int d=0;
    int r;
    do{ 
        char tmp2[20];char tmp[20];
        printf("\nJepni id e artikullit : ");
		scanf("%s",tmp2); fflush(stdin);
		strcpy(tmp,tmp2); fflush(stdin);
        /*kam perdorur 2 var te tipit char tmp sepse nuk me ndodhte 
        mbivendosja e id se artikullit qe do te shtohej gjate 
        ciklit te dyte*/
		for(int i=0;i<nr_art; i++)//gjejm artikullin
			if(strcmp(tmp, art[i].id)==0){
				printf ("\nJepni sasine e \"%s\": ",art[i].emertimi);//marrim sasine
				scanf("%d", &f->fd[d].sasia);
                fflush(stdin);
				//marrim cmimin per nje artikull
                f->fd[d].cmimi=art[i].cmimi;
                //gjejm vleren per x artikuj
                f->fd[d].vlera=f->fd[d].cmimi*f->fd[d].sasia;
                printf("\nVlera: %d leke",f->fd[d].vlera);
                //gjejm sasie totale te produktit
                art[i].sasia=art[i].sasia + f->fd[d].sasia;
                printf("\nSasia totale e artikullit: %d",art[i].sasia);
                fflush(stdin);
                d++;
			}
		printf("\n Deshironi te shtoni artikull tjeter (P/J):");
        fflush(stdin);
		scanf("%c", &c);
		if (c=='J'||c=='j')
			break;
    }while(1);
    nr_furnizimi++;
    f[nr_furnizimi];
}

void klientet_blejne_shpesh(){
    int max;int nr,kushti;
    printf("\nZgjedhja:  k_b_shpesh!\n");
    printf("\n====Renditja e klienteve!====\n");
    do{
    kushti=1;
    max=k[0].shpeshtesia;
    for (int i = 1; i < nr_klient; i++)
    {
        if (max<k[i].shpeshtesia)
        {
            max = k[i].shpeshtesia;
            nr = i;
        } 
    }
    printf("\nKlienti k[%d] !",nr);
    printf("\nEmri: %s ",k[nr].emri);
    printf("\nMbiemri: %s ",k[nr].mbiemri);
    printf("\nKa blere %d here! ",k[nr].shpeshtesia);
    printf("\nNumer tel. %s ",k[nr].tel);
    k[nr].shpeshtesia=0;
    printf("\nShtypni tastin 0 nese doni te shfaqet klienti tjeter ne renditje: ");
    scanf("%d",&kushti);}
    while(kushti==0);
}

void klientet_blejne_shume(){
    int max;int nr,kushti;
    printf("\nZgjedhja k_b_shume !\n");
    printf("\n====Renditja e klienteve!====\n");
    do{
    kushti=1;
    max=k[0].total;
    for (int i = 1; i < nr_klient; i++)
    {
        if (max<k[i].total)
        {
            max = k[i].total;
            nr = i;
        } 
    }
    printf("\nKlienti k[ %d ]",nr);
    printf("\nEmri klientit: %s ",k[nr].emri);
    printf("\nMbiemri klientit: %s ",k[nr].mbiemri);
    printf("\nTel. klientit: %s ",k[nr].tel);
    printf("\nKa blere ne total %.2f leke",k[nr].total);
    k[nr].total=0;
    printf("\nShtypni tastin 0 nese doni te shfaqet klienti tjeter ne renditje: ");
    scanf("%d",&kushti);}
    while(kushti==0);
}

void kerkim_artikulli(){
    char tmp[20];int numri2;
	printf("\nKerkim artikulli: ");
	printf("\nJepni ID: ");
	
	scanf("%s",tmp);
	//kontrollojm nese eshte i regjistruar
    int kushti = 0;
	for(int i=0; i<nr_art;i++){
		if (strcmp(art[i].id,tmp)==0){
			printf("\nKjo id i perket artikullit art[%d]!",i);
            numri2 = i;
            kushti = 1;
		}
	}

    if(kushti == 0){
        printf("\nId se vendosur nuk i pergjigjet asnje artikull!");
        return;
    }
    
	printf("\nEmri i artikullit: %s ",art[numri2].emertimi);
	printf("\nKategoria e artikullit: %s ",art[numri2].kategoria);
	printf("\nCmimi i artikullit: %d ",art[numri2].cmimi);
    printf("\nSasia e artikullit: %d ",art[numri2].sasia);
}

void gjendja_magazine(){
    char tmp[20];int numri2;
    printf("\n===Gjendja ne magazine===");
    printf("\nVendosni id e artikullit: ");
    scanf("%s",tmp);
    fflush(stdin);

    //kontrolloj nese ekziston si artikull
    int kushti = 0;
    for(int i=0;i<nr_art;i++){
        if(strcmp(art[i].id,tmp)==0){
            kushti = 1;
            numri2 = i;
        }
    }

    if (kushti==0)
    {
        printf("\nKy artikull nuk eshte i regjistruar");
        return;
    }
    
    printf("\nSasia ne magazine e ketij artikulli eshte: %d ",art[numri2].sasia);
    return;
}

void save(){
	FILE *f;
	f=fopen("C:\\cp\\Artikulli.bin","wb");
	if (f==NULL){
		printf("\n \n   Gabim ne file");
		return;
	}
	 
	for(int i=0;i<nr_art; i++){
		fwrite(&art[i],sizeof(struct artikulli),1,f);
	}
	fclose(f);
	
	f=fopen("C:\\cp\\Klienti.bin","wb");
	if (f==NULL){
		printf("\n \n   Gabim ne file");
	    return;
	}
	 
	for(int i=0;i<nr_klient; i++){
		fwrite(&k[i],sizeof(struct klienti),1,f);
	}
	fclose(f);
	
	f=fopen("C:\\cp\\Shitje.bin","wb");
	if (f==NULL){
		printf("\n \n   Gabim ne file");
	    return;
    }

	for(int i=0;i<id_fatura; i++){
		fwrite(&s[i],sizeof(struct shitje),1,f);
	}
	fclose(f);
	
	f=fopen("C:\\cp\\Furnizimi.bin","wb");
	if (f==NULL){
		printf("\n \n   Gabim ne file");
	    return;
	}
	 
	for(int i=0;i<nr_furnizimi; i++){
		fwrite(&f[i],sizeof(struct furnizim),1,f);
	}
	fclose(f);
}

void lexo()
{
	FILE *f;
 	f=fopen("C:\\cp\\Artikulli.bin","rb");
 	if (f==NULL){
   		printf("\n \n   Gabim ne file");
   		return;
 	}
 	nr_art=0;
 	fflush(stdin);
 
 	while (fread(&art[nr_art],sizeof(struct artikulli),1,f))
 	{
   		nr_art++;
 	} 
 
 	fclose(f); 
 
 	f=fopen("C:\\cp\\Klienti.bin","rb");
 	if (f==NULL)
 	{
   		printf("\n \n   Gabim ne file");
   		return;
 	}
 
 	nr_klient=0;
 
 	while (fread(&k[nr_klient],sizeof(struct klienti),1,f))
 	{
   		nr_klient++;
 	} 
 
 	fclose(f); 
  	
  	f=fopen("C:\\cp\\Shitje.bin","rb");
 	if (f==NULL)
 	{
   		printf("\n \n   Gabim ne file");
   		return;
 	}
 
 	id_fatura=0;
 
 	while (fread(&s[id_fatura],sizeof(struct shitje),1,f))
 	{
   		id_fatura++;
 	} 
 
 	fclose(f); 
 	
 	f=fopen("C:\\cp\\Furnizimi.bin","rb");
 	if (f==NULL)
 	{
   		printf("\n \n   Gabim ne file");
   		return;
 	}
 
 	nr_furnizimi=0;
 
 	while (fread(&k[nr_furnizimi],sizeof(struct furnizim),1,f))
 	{
   		nr_furnizimi++;
 	} 
 
 	fclose(f); 
}


int main(){
    char k;
    do{
        menu();
        k=getch();
        if(k=='1'){ regjistro_artikull();}
        else if (k=='2'){regjistro_klient();}
        else if (k=='3'){shto_furnizim();}
        else if (k=='4'){shitje();}
        else if (k=='5'){gjendja_magazine();}
        else if (k=='6'){klientet_blejne_shume();}
        else if (k=='7'){klientet_blejne_shpesh();}
        else if (k=='8'){kerkim_artikulli();}
        else if (k=='S' || k=='s'){save();}
        else if (k=='L' || k=='l'){lexo();}
    }
    while(k!='d'&&k!='D'&&k!=27);
}

