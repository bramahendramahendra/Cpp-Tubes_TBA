#include "header.h"

void createList(List &L){
    L.first = NULL;
}

void createList2(List2 &L){
    L.first2 = NULL;
}

adr alokasi(infotype x){
    adr P = new Elm;
    P->info = x;
    P->next = NULL;
    return P;
}
adr2 alokasi2(infotype2 x){
    adr2 P = new Elm2;
    P->info2 = x;
    P->next2 = NULL;
    return P;
}

void insertLast(List &L, adr P){
    if (L.first == NULL){
        L.first = P;
    } else {
        adr Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertLast2(List2 &L, adr2 P){
    if (L.first2 == NULL){
        L.first2 = P;
    } else {
        adr2 Q = L.first2;
        while (Q->next2 != NULL) {
            Q = Q->next2;
        }
        Q->next2 = P;
    }
}

void printInfo(List L){
    if (L.first == NULL){
        cout<<"Error\n";
    } else {
        adr P = L.first;
        while (P != NULL){
            cout<<P->info<<" ";
            P=P->next;
        }
        cout<<endl;
    }
}
void printInfo2(List2 L){
    if (L.first2 == NULL){
        cout<<"Error\n";
    } else {
        adr2 P = L.first2;
        while (P!= NULL){
            cout<<P->info2<<" ";
            P=P->next2;
        }
        cout<<endl;
    }
}

void token(string s, List &L1, List2 &L2, adr P, adr2 Q){
    int i, pjg,a;
    char c,c2;
    string kode[1000];
    pjg = s.length();
    kode[0] = "kosong";
    a=1;
    for (i=0; i<pjg;i++){
        c = s[i];
        c2 = s[i+1];
        if (c == '0'||c=='1'||c == '2'||c == '3'||c == '4'||c == '5'||c == '6'||c == '7'||c == '8'||c == '9'||c == 'E'){
            P = alokasi(c);
            insertLast(L1, P);
            if (kode[a-1] != "angka") {
                Q = alokasi2("angka");
                insertLast2(L2, Q);
                kode[a] = "angka";
                a++;
            }
        }
        if (c == '+'){
            P = alokasi(c);
            insertLast(L1,P);

            Q = alokasi2("operator");
            insertLast2(L2,Q);
            kode[a] = "operator";
            a++;
        }
        if (c== '-'){
            P = alokasi(c);
            insertLast(L1,P);
            if (kode[a-1] == "kosong"){
                    if (c2 == '0'||c2=='1'||c2 == '2'||c2 == '3'||c2 == '4'||c2 == '5'||c2 == '6'||c2 == '7'||c2 == '8'||c2 == '9'||c2 == 'E') {
                        Q = alokasi2("angka");
                        insertLast2(L2,Q);
                        kode[a] = "angka";
                        a++;
                    }
            }
            else {
                Q = alokasi2("operator");
                insertLast2(L2,Q);
                kode[a] = "operator";
                a++;
            }
        }
        if (c== 'x'){
            P = alokasi(c);
            insertLast(L1,P);
            Q = alokasi2("operator");
            insertLast2(L2,Q);
            kode[a] = "operator";
            a++;
        }
        if (c== ':'){
            P = alokasi (c);
            insertLast(L1,P);
            Q = alokasi2("operator");
            insertLast2(L2,Q);
            kode[a] = "operator";
            a++;
        }
        if (c==','){
            P = alokasi (c);
            insertLast(L1,P);
            if (kode[a-1] != "angka"){
                Q = alokasi2("simbol");
                insertLast2(L2,Q);
                kode[a] = "simbol";
                a++;
            }
        }
         if (c== ')'){
            P = alokasi (c);
            insertLast(L1,P);
                Q = alokasi2("simbol");
                insertLast2(L2,Q);
                kode[a] = "simbol";
                a++;

         }
          if (c== '('){
            P = alokasi (c);
            insertLast(L1,P);
                Q = alokasi2("simbol");
                insertLast2(L2,Q);
                kode[a] = "simbol";
                a++;
          }
    }
}

void validasi(List &L1, List2 &L2) {

	int banyak,total;
	char kata[100];
	string kalimat[1000];
	banyak = 0;
	total = 0;


	adr P = L1.first;
	while (P != NULL) {
		kata[banyak] = P->info;
		banyak++;
		P = P->next;
	}

	adr2 Q = L2.first2;
	while (Q != NULL) {
		kalimat[total] = Q->info2;
		total++;
		Q = Q->next2;
	}

    int i = 0;
	string test ;
	while (i<=total) {
		if(kalimat[i] == "simbol" && kalimat[i-1] == "simbol"){
			test = "Tidak Valid";
			break;
        }
		else if(kalimat[i] == "operator" && kalimat[i-1] == "operator"){
			test = "Tidak Valid ";
			break;
		} else {
            test = "Valid ";
        }


		//if(arr[i+1] == 'Error'){
		//	cout<<" = Tidak Valid "<<endl;

	//	} else {
	//		cout<<" = Valid "<<endl;
	//	}
		i++;
	}
	cout<<test<<endl;
}


