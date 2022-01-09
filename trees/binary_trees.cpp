#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node *build(){
    int d;
    cin>>d;
    if(d==-1) return NULL;

    node *root=new node(d);
    root->left = build();
    root->right = build();
    return root;
};

void preorder(node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void postorder(node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}

void inorder(node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

void preorder_iterative(node *root){
    if(root==NULL) return;
    stack<node*> st;
    st.push(root);
    while(not st.empty()){
        cout<<st.top()->data<<" ";
        node *cur = st.top();
        st.pop();
        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
    }
    return;
}

void levelorder(node *root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(not q.empty()){
        cout<<q.front()->data<<" ";
        node *cur = q.front();
        q.pop();
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    return;
}

void level_order_levelwise(node *root){
    if(root==NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(not q.empty()){
        if( q.front()==NULL ){
            cout<<"\n";
            q.pop();
            if(q.empty()) break;
            cout<<q.front()->data<<" ";
            q.push(NULL);
            continue;
        }
        cout<<q.front()->data<<" ";
        node *cur = q.front();
        q.pop();
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    return;
}

void right_view(node *root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    
    while(not q.empty()){
        int size = q.size();
        vector<int> v;
        for(int i=0;i<size;i++){
            
            v.push_back(q.front()->data);
            node *cur = q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        cout<<v[v.size()-1];
    }
} 

void left_view(node *root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(not q.empty()){
        int size = q.size();
        vector<int> v;
        for(int i=0;i<size;i++){
            v.push_back(q.front()->data);
            node *cur = q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        cout<<v[0]<<" ";
    }
} 

int height_0f_tree(node *root){
    if(root==NULL) return 0;
    if(root->left==NULL and root->right==NULL) return 0;

    int lh = height_0f_tree(root->left);
    int rh = height_0f_tree(root->right);

    return (max(lh,rh)+1);
}

int diameter(node *root){
    if(root==NULL) return 0;
    if(root->left==NULL and root->right==NULL) return 0;

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    int lh = height_0f_tree(root->left);
    int rh = height_0f_tree(root->right);
    int via_root = lh + rh + (root->left!=NULL) + (root->right!=NULL);

    return max({ld,rd,via_root});
}

//pair is used to store <diameter , height>
pair<int,int> diameter_diff_pproach(node *root){
    if( (root==NULL) or (root->left==NULL and root->right==NULL)){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    };

    pair<int,int> left = diameter_diff_pproach(root->left);
    pair<int,int> right = diameter_diff_pproach(root->right);

    int h = max(left.second,right.second) + 1;
    int d = max({left.first, right.first, left.second + right.second + 2 });

    return {d,h};
}

int lw=0;
int rw=0;

void top_view(node *root,int clw,int crw){
    if(root==NULL) return;
    if(clw==0 and lw==0){
        cout<<root->data<<" ";
    }
    if(clw<lw){
        lw = clw;
        cout<<root->data<<" ";
    }
    if(crw>rw){
        rw=crw;
        cout<<root->data<<" ";
    }
    if(root->left) top_view(root->left,clw-1,crw-1);
    if(root->right) top_view(root->right,clw+1,crw+1);
    return;
}


vector<vector<int>> res;

void zig_zag_traversal(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    
    while(not q.empty()){
        
        vector<int> temp_arr;
        int size = q.size();

        for(int i=0;i<size;i++){
            node* cur = q.front();
            q.pop();
            temp_arr.push_back(cur->data);
            if(cur->left) q.push(cur->left); 
            if(cur->right) q.push(cur->right);
        }
        res.push_back(temp_arr);
    }
}

void mirror_tree(node *root){
    if(root==NULL){
        return ;
    }

    node *t = root->left;
    root->left = root->right;
    root->right = t;

    if(root->left) mirror_tree(root->left);
    if(root->right) mirror_tree(root->right);

    return;
}

// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

struct Info{
    int max_size;
    int min;
    int max;
    int size;
    bool isBST;
};

Info largestBST(node *root){
    if(root==NULL){
        return {0,INT_MAX,INT_MIN,0,true};
    }

    if(root->left==NULL and root->right==NULL){
        return {1,root->data,root->data,1,true};
    }

    Info l = largestBST(root->left);
    Info r = largestBST(root->right);

    Info ret;
    ret.size = (l.size+r.size+1);

    if(l.isBST and r.isBST and l.max<root->data and r.min>root->data){
        ret.min = min(l.max,min(r.min,root->data));
        ret.max = max(r.max,max(root->data,l.max));
        ret.max_size = ret.size;
        ret.isBST = true;
    }else{
        ret.isBST = false;
        ret.max_size = max(l.max_size,r.max_size);
    }
    return ret;
}



int main(){
    node *root = build();
    // preorder(root);
    // cout<<"\n";
    // postorder(root);
    // cout<<"\n";     
    // inorder(root);
    // preorder_iterative(root);
    // levelorder(root);
    // level_order_levelwise(root);
    // right_view(root);
    // left_view(root);
    // cout<<height_0f_tree(root)<<endl;
    // cout<<diameter(root)<<endl;
    // pair<int,int> d = diameter_diff_pproach(root);
    // cout<<d.first<<" "<<d.second;
    // top_view(root,0,0);

    // zig_zag_traversal(root);

    // for(int i;i<res.size();i++){
    //     if(i%2==0){
    //         for(int j=0;j<res[i].size();j++){
    //             cout<<res[i][j]<<" ";
    //         }
    //     }else{
    //          for(int j=res[i].size()-1;j>=0;j--){
    //             cout<<res[i][j]<<" ";
    //         }
    //     }
    // } 

    // mirror_tree(root);
    // Info ans = largestBST(root);
    // cout<<ans.max_size;


    return 0;
}


// 20 8 5 -1 -1 3 10 -1 -1 14 -1 -1 22 -1 25 -1 -1
// 6 6 -1 2 -1 8 -1 -1 3 9 8 -1 -1 2 -1 -1 3 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 -1 7 -1 -1

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

// 1 2 -1 5 -1 -1 3 -1 4 -1 -1   preorder build

            //     1
            // 2       3
            //   5        4

// 1 2 -1 4 -1 7 -1 -1 3 5 -1 8 -1 10 -1 12 -1 -1 6 -1 9 -1 11 -1 13 -1 14 -1 -1