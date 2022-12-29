#include<bits/stdc++.h>
using namespace std;


string xor1(string a, string b)
{
	

	string result = "";
	
	int n = b.length();
	

	for(int i = 1; i < n; i++)
	{
		if (a[i] == b[i])
			result += "0";
		else
			result += "1";
	}
	return result;
}


string mod2div(string dividend, string divisor)
{
	

	int pick = divisor.length();
	
	
	string tmp = dividend.substr(0, pick);
	
	int n = dividend.length();
	
	while (pick < n)
	{
		if (tmp[0] == '1')
		
		
			tmp = xor1(divisor, tmp) + dividend[pick];
		else
		
		
			tmp = xor1(std::string(pick, '0'), tmp) +
				dividend[pick];
				

		pick += 1;
	}
	

	if (tmp[0] == '1')
		tmp = xor1(divisor, tmp);
	else
		tmp = xor1(std::string(pick, '0'), tmp);
		
	return tmp;
}
bool receiver(string data, string key)
{
	string s = mod2div(data, key);
	
	for(int i=0;i<s.length();i++)
	{
	    if(s[i]!='0')
	    {
	        return false;
	    }
	}
	return true;
	
	
}


void encodeData(string data, string key)
{
	int l_key = key.length();
	
	
	string appended_data = (data +
							std::string(
								l_key - 1, '0'));
	
	string remainder = mod2div(appended_data, key);
	

	string codeword = data + remainder;
	cout << "Remainder : "
		<< remainder << "\n";
	cout << "Encoded Data (Data + Remainder) :"
		<< codeword << "\n";
	
	if(receiver(codeword,key))
	{
	    cout<<"Correct Message is recieved";
	}
	else{
	    cout<<"Data is corrupted";
	}
}

int main()
{
	string data = "1011101";
	string key = "1000100000010001";
	
	encodeData(data, key);
	
	return 0;
}
