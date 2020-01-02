#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
  string line;
  ifstream myfile ("input.txt");
  int sayac=0;
  int soru_sayisi;
  string cevap_anahtari;
  int notlar[100]={0};
  int ogrenci=0;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
      
      if(sayac==0)
      {
      	soru_sayisi = atoi(line.c_str());
	  }
	  
	  if(sayac==1)
	  {
	  	cevap_anahtari = line;
	  }
	  
	  else
	  {
	  	int soru = 1;
	  	int i = 9;
	  	while(1)
	  	{
	  		
			if(line[i]=='\0')
			{
				break;
			} 	
	  		
	  		if(line[i]==','&&line[i+1]==',')
	  		{
	  			soru += 1;
			}
			
			if(line[i]==','&&line[i+1]!=',')
			{
				soru += 1;
				
				if(cevap_anahtari[soru*2]==line[i+1])
				{
					notlar[ogrenci] += 4;
				}
					
				else
				{
					notlar[ogrenci] -= 1;
				}
			}
			
		i+=1;
		ogrenci+=1;
		
		if(soru>19)
		{
			break;
		}	
		
		cout << "\ncevaplar: ";
	  		cout << line[i] << "\n";	
			
		}
		
		
		
	  }
      
      sayac += 1;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

	for(int i=0;i<ogrenci;i++)
	{
		cout << notlar[i];
	}

  return 0;
}
