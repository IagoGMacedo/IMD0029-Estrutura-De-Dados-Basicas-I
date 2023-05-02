#include <cassert>
#include <iostream>
#include <string>

using namespace std;

string selectionSort(string s1){
	unsigned int min;
	for(unsigned int i =0; i < s1.size() - 1; i++){
		min = i;
		for(unsigned int j =i+1;j<s1.size();j++){
			if(s1[j]<s1[min]){
				min = j;
			}
		}
		//SWAP
		if(min!=i){
			char aux = s1[i];
			s1[i] = s1[min];
			s1[min] = aux;
		}
		
	}
	return s1;
}

bool isAnagram(string s1, string s2)
{
	if(!s1.empty() && !s2.empty()){
		s1 = selectionSort(s1);
		s2 = selectionSort(s2);
		return (s1==s2);
	}
	return s1.empty()==s2.empty();
}

int main(void)
{
	// São anagramas entre si
	assert( isAnagram("", "") == true );
	assert( isAnagram("A", "A") == true );
	assert( isAnagram("AB", "BA") == true );
	assert( isAnagram("AVAL", "VALA") == true );
	assert( isAnagram("LAVA", "VALA") == true );
	assert( isAnagram("FENO", "FONE") == true );
	assert( isAnagram("AMERIC", "MERICA") == true );
	assert( isAnagram("IRACEMA", "AMERICA") == true );
	assert( isAnagram("IRACEMA", "IRACEMA") == true );
	assert( isAnagram("AMERICA", "AMERICA") == true );
	
	// Não são anagramas entre si
	assert( isAnagram("AMERICA", "MER") == false );
	assert( isAnagram("RICA", "AMARACA") == false );
	assert( isAnagram("", "AMARACA") == false );
	assert( isAnagram("RICA", "") == false );
	assert( isAnagram("BOLA", "BALA") == false );

	std::cout << "Q3_Anagram - Passou em todos os testes!" << std::endl;

	return 0;
}
