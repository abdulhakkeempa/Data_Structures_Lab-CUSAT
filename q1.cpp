#include <iostream>
using namespace std;

void insert(int sampleArray[],int pos,int size){
    int orgArray[size+1];
    for (int i = 0; i < pos; i++)
    {
        orgArray[i] = sampleArray[i];
    }
    orgArray[pos] = 36;
    for (int i = pos+1; i <= size+1; i++)
    {
        orgArray[i] = sampleArray[i-1];
    }
    for (int i = 0; i <= size+1; i++)
    {
        cout<<orgArray[i]<<endl;
    }
}


int main(){
    int arr[] = {10,20,30,40,50,60,70,80};
    insert(arr,7,7);




    // int const size = 5;
    // int arr[size];   
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<i+1<<"th Position : ";
    //     cin>>arr[i];
    // }
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<i+1<<"th Position : ";
    //     cout<<arr[i]<<endl;
    // }
    // int key;
    // cout<<"Enter the Position from which you want to remove the element"<<endl;
    // cin>>key;
    // for (int i = key-1; i < size-1; i++)
    // {
    //     arr[i]=arr[i+1];
    // }

    // int insertionPosition;
    // cout<<"Enter the position where you want to insert"<<endl;
    // cin>>insertionPosition;

    // int newArray[size+1];


    // for (int i = 0; i < size; i++)
    // {
    //     cout<<i+1<<"th Position : ";
    //     cout<<arr[i]<<endl;
    // }
    return 0;
}
