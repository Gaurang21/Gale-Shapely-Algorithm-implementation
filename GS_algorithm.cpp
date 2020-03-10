/******************************************************************************

Name 	: Gaurang Suki
Net ID 	: zs9267
GS Algorithm Implementation
*******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;
void printPreference(int **preference, int n) // function for printing preference matrix
{
    for(int i=0;i<n;i++)
    {
        cout<<"\n";
        for(int j=0;j<n;j++)
        {
            cout<<"\t"<<preference[i][j];
        }
    }
    cout<<"\n";
}
int getIndex(string s) // function to return index 
{
    char men[5][10] = { "V", "W", "X", "Y","Z" }; 
    char women[5][10] = { "A", "B", "C", "D","E" }; 
    for (int i=0; i< 5;i++) 
    {
        if(men[i]==s)
        {
            return i;
        }
        if(women[i]==s)
        {
            return i;
        }
    }
}
string getNameMen(int x) // function to get names of men according to index
{
    char men[5][10] = { "Victor", "Wyatt", "Xavier", "Yancey","Zeus" }; 
    return men[x];
}
string getNameWomen(int x) // function to get names of women according to index
{
    char women[5][10] = { "Amy", "Bertha", "Claire", "Diane","Erika" }; 
    return women[x];
}
int main()
{
    int n;
    cout<<"Enter the no of men and women"<<endl;
    cin>>n;
    
    int **preferenceMen = new int*[n];
    for(int i = 0; i < n; i++) {
    preferenceMen[i] = new int[n];
    }
    
    int **preferenceWomen = new int*[n];
    for(int i = 0; i < n; i++) {
    preferenceWomen[i] = new int[n];
    }
    cout<<"Enter initials only "<<endl;
    cout<<"Enter preference list of men "<<endl;
    string s_woman;
    int ind;
    for(int i=0;i<n;i++)
    {
	cout<<"Enter preference of man "<<i+1<<endl;
        for(int j=0;j<n;j++)
        {
        cout<<"Enter name of woman "<<j+1<<endl;
        cin>>s_woman;
        ind = getIndex(s_woman);  // get index of woman from the list
        preferenceMen[i][j]=ind; // store index in the matrix
        }
    }   
    printPreference(preferenceMen,n);
    cout<<"Enter preference list of women"<<endl;
    int pref=0;
    string s_man;
    for(int i=0;i<n;i++)
    {
	cout<<"Enter preference of woman "<<i+1<<endl;
        for(int j=0;j<n;j++)
        {
        cout<<"Enter name of man "<<j+1<<endl;
        cin>>s_man;
        pref=getIndex(s_man);
        preferenceWomen[i][pref]=j; // store index in inverse order
        }
    }
    printPreference(preferenceWomen,n);
    queue <int> menQueue;  // Use queue to store index of men
    for(int i=0;i<n;i++)
    {
        menQueue.push(i);
        cout<<menQueue.back();
    }
    int *wife=new int[n]; // store match
    int *husband=new int[n]; // store match
    int *count=new int[n]; // to store no of women a man proposes
    
    for(int i=0;i<n;i++) // initialisation
    {
        wife[i]=-1;
        husband[i]=-1;
        count[i]=0;
    }
    while(menQueue.size()!=0) //keep going till all the men are occupied
    {
        int man = menQueue.front(); // get first man from the queue
        menQueue.pop();
        //cout<<man;
        if(count[man]==n) // if a man proposes to every woman
        {
            continue;
        }
        int woman = preferenceMen[man][count[man]]; // get woman that the man has not proposed yet
        if(husband[woman]==-1) // if woman free
        {
            husband[woman]=man;
            wife[man]=woman;
        }
        else if(preferenceWomen[woman][man]<preferenceWomen[woman][husband[woman]]) // if woman prefers a man more than her current husband
        {
            menQueue.push(husband[woman]);
            husband[woman]=man;
            wife[man]=woman;
        }
        else
        {
            menQueue.push(man);
        }
        count[man]++;
    }

    for(int k=0;k<n;k++)
    {
        cout<<getNameMen(husband[k])<<" --- marries --- "<<getNameWomen(wife[husband[k]])<<endl; // get names of men and womand 
    }
return 0;    
}
/*
Enter the no of men and women
5
Enter initials only 
Enter preference list of men 
Enter preference of man 1
Enter name of woman 1
B
Enter name of woman 2
A
Enter name of woman 3
D
Enter name of woman 4
E
Enter name of woman 5
C
Enter preference of man 2
Enter name of woman 1
D
Enter name of woman 2
B
Enter name of woman 3
A
Enter name of woman 4
C
Enter name of woman 5
E
Enter preference of man 3
Enter name of woman 1
B
Enter name of woman 2
E
Enter name of woman 3
C
Enter name of woman 4
D
Enter name of woman 5
A
Enter preference of man 4
Enter name of woman 1
A
Enter name of woman 2
D
Enter name of woman 3
C
Enter name of woman 4
B
Enter name of woman 5
E
Enter preference of man 5
Enter name of woman 1
B
Enter name of woman 2
D
Enter name of woman 3
A
Enter name of woman 4
E
Enter name of woman 5
C

	1	0	3	4	2
	3	1	0	2	4
	1	4	2	3	0
	0	3	2	1	4
	1	3	0	4	2
Enter preference list of women
Enter preference of woman 1
Enter name of man 1
Z
Enter name of man 2
V
Enter name of man 3
W
Enter name of man 4
Y
Enter name of man 5
X
Enter preference of woman 2
Enter name of man 1
X
Enter name of man 2
W
Enter name of man 3
Y
Enter name of man 4
V
Enter name of man 5
Z
Enter preference of woman 3
Enter name of man 1
W
Enter name of man 2
X
Enter name of man 3
Y
Enter name of man 4
Z
Enter name of man 5
V
Enter preference of woman 4
Enter name of man 1
V
Enter name of man 2
Z
Enter name of man 3
Y
Enter name of man 4
X
Enter name of man 5
W
Enter preference of woman 5
Enter name of man 1
Y
Enter name of man 2
W
Enter name of man 3
Z
Enter name of man 4
X
Enter name of man 5
V

	1	2	4	3	0
	3	1	0	2	4
	4	0	1	2	3
	0	4	3	2	1
	4	1	3	0	2
Victor --- marries --- Amy
Xavier --- marries --- Bertha
Wyatt --- marries --- Claire
Zeus --- marries --- Diane
Yancey --- marries --- Erika


*/




