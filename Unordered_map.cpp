#include<bits/stdc++.h>
using namespace std;
#define mod %

template<class T, class X>
class UnorderedMap
{
    public:
    struct node{
        T key;
        X value;
        node* next;
    };
    int bucket=10000;
    struct node* hashmap[10000];
    int prime=1543;


    public:
    UnorderedMap()
    {
        for(int i=0;i<bucket;i++)
        {
            hashmap[i]=NULL;
        }
    }
    int hash(string data)
    {
        //used universal hashing for strings
        //and had referred `bernstein` hash function for h value and a value;
        //string s=string(data+"");
        int h=5381;
        int a=33;
        int n=data.length();
        for (int i=0;i<n;i++)
        {
            h=((h*a)+data[i]) mod prime;
        }
        return h;
    }
    
    node* createnode(T data, X val)
    {
        node* temp=(struct node*)malloc(sizeof(node));
        temp->key=data;
        temp->value=val;
        temp->next=NULL;
        //cout<<"inside create";
        return temp;
    }
    
    void insert(T data, X val)
    {
        //string s=string(data+"");
        ostringstream os; 
        os<<data; 
        int index=hash(os.str());
        //cout<<index<<endl;
        struct node* root=hashmap[index];
        //cout<<"hey";
        if(root==NULL)
        {
            root=createnode(data,val);
            //cout<<"hello";
            hashmap[index]=root;
            return;
        }
        else if(root!=NULL)
        {
            //yadi ek node hi hai to usko hi check kr lo
            //cout<<"Bye";
            if(root->next==NULL)
            {
                if(root->key==data)
                    return;
                node* p=createnode(data,val);
                root->next=p;
                return;
            }
            else
            {
                //pehle se present hai ki nhi dekh lo chain me
                node* temp=root;
                while(temp->next!=NULL)
                {
                    if(temp->key==data)
                        return;
                    else
                        temp=temp->next;
                }

                // yaha aa gaya mltb pehle se present nhi hai chain me to insert krwa do
                node* p=createnode(data,val);
                temp->next=p;

                return;
            }
        }
    }



    void erase(T data)
    {
        ostringstream os; 
        os<<data; 
        int index=hash(os.str());
        //cout<<index<<" ";
        node* root=hashmap[index];

        if(root==NULL)
            return; 
        
        else if(root!=NULL)
        {
            //yadi single node hai to usko check kro 
            if(root->next==NULL)
            {
                if(root->key==data)
                {
                    //root=NULL;
                    hashmap[index]=NULL;
                    free(root);
                }
                else return;
            }

            //yadi chain hai to
            else
            {
                node* temp=root;
                node* prev;
                node* p;
                if(temp->key==data)
                {
                    root=temp->next;
                    free(temp);
                    return;
                }
                while(temp!=NULL)
                {
                    if(temp->key==data)
                    {
                        p=temp;
                        break;
                    }
                    prev=temp;
                    temp=temp->next;
                }
                prev->next=p->next;
                free(p);
            }
        }
    }


    int find(T data)
    {
        ostringstream os; 
        os<<data; 
        int index=hash(os.str());
        node* root=hashmap[index];
        if(root==NULL)
            return 0;

        else
        {
            if(root->next==NULL)
            {
                if(root->key==data)
                    return 1;
                
                else return 0;
            }
            node* temp=root;
            while(temp!=NULL)
            {
                if(temp->key==data)
                {
                    return 1;
                }
                temp=temp->next;
            }
        }
        return 0;
    }


    X &operator[](T data)
    {
       ostringstream os; 
        os<<data; 
        int index=hash(os.str());
        node* root=hashmap[index];
        node* temp=root;
        node* p;
        while(temp!=NULL)
        {
            if(temp->key==data)
            {
                p=temp;
                break;
            }
            temp=temp->next;
        }
        return p->value;
    }

};


int main()
{
    UnorderedMap<string,int> m;
    m.insert("abc",2);
    m.insert("ubg",6);
    m.insert("xcd",20);
    m.insert("lkj",5);
    cout<<m["abc"]<<endl;
    cout<<m.find("xcd")<<endl;
    cout<<m.find("abc")<<endl;
    cout<<m.find("ubg")<<endl;
    m.erase("xcd");
    m.erase("abc");
   // m.erase("ubg");
    m.erase("lkj");
    cout<<m.find("xcd")<<endl;
    cout<<m.find("abc")<<endl;
    cout<<m.find("ubg")<<endl;
    cout<<m["ubg"]<<endl;

    UnorderedMap<int,int> mp;
    mp.insert(30,1);
    mp.insert(10,2);
    mp.insert(20,3);
    mp.insert(40,4);
    mp.insert(50,5);
    mp.insert(25,6);
    mp.insert(35,7);
    mp.insert(156,8);
    mp.insert(31,1);
    mp.insert(32,1);
    mp.insert(33,1);
    mp.insert(34,1);
    mp.insert(35,1);
    mp.insert(38,1);
    mp.insert(37,1);
    mp.insert(39,1);
    mp.insert(138,1);

    UnorderedMap<float,int> u;
    u.insert(2.2,4);
    u.insert(2.9,4);
    u.insert(11.6,4);
    u.insert(25.27,4);
    cout<<u[2.2]<<endl;
    cout<<u[2.9]<<endl;
    cout<<u[11.6]<<endl;
    cout<<u[25.27]<<endl;

    UnorderedMap<char,int> k;
    k.insert('a',4);
    k.insert('b',4);
    k.insert('c',4);
    k.insert('d',4);
    cout<<k['a']<<endl;
    cout<<k['b']<<endl;
    cout<<k['c']<<endl;
    cout<<k['d']<<endl;


}