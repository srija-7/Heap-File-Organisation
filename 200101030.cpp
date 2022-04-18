#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define V(a) vector<a>
#define P(a,b) pair<a,b>
#define Sort(a) sort(a.begin(),a.end())

class page{
    public:
    V(int) key;
    V(int) data_size;
    int count;
    int size_left;

    
    page(int pg_size){
        count=0;
        size_left=pg_size-4*4;
    }

    int search(int a){
        auto it=find(key.begin(),key.end(),a);
        if(it==key.end())
            return -1;
        
        return it-key.begin();
    }
    

    bool insert(int d_size,int p_key){
        if(size_left-d_size-4<=0)
            return false;
        size_left-=d_size-4;
        key.push_back(p_key);
        data_size.push_back(d_size);
        count++;
        return true;
    }
    int get_count(){
        return count;
    }
};

class file{
    public:
    V(page) pg;
    int page_size;

    file(int pg_size){
        page_size=pg_size;
    }

    void search(int key){
        for(int i=0;i<pg.size();i++){
            int t=pg[i].search(key);
            if(t>=0){
                cout<<i<<" "<<t<<"\n";
                return;
            }            
        }
        cout<<"-1 -1\n";
        return;
    }

    void display(){
        cout<<pg.size()<<" ";
        for(auto i:pg)
            cout<<i.get_count()<<" ";
        cout<<"\n";
        return;
    }

    void insert(int d_size,int key){
        int check=0;
        for(int i=0;i<pg.size();i++){
            if(pg[i].insert(d_size,key)==true){
                check=1;
                break;
            }
        }
        if(check==0){
            pg.push_back(page_size);
            if( pg[pg.size()-1].insert(d_size,key) == -1 ){
                cout<<"Cannot insert this data\n";
            }
        }
    }
};

int main(){

    int page_size;
    cin>>page_size;

    file file1(page_size);
    while(1){
        int x;
        cin>>x;
        if(x==1){
            int data_size,key;
            cin>>data_size>>key;
            file1.insert(data_size,key);
        }
        else if(x==2){
            file1.display();
        }
        else if(x==3){
            int key;
            cin>>key;
            file1.search(key);
        }
        else if(x==4){
            break;
        }
    }
    //cout<<"phew.. i am out of an infinite loop.\n";
    
    return 0;
}