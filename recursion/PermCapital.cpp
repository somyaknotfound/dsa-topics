void PermCapital(string ip , string op) {
    if (ip.length() == 0) {
        cout << op << endl;
        return;
    }
    
    string op1 = op;
    string op2 = op;
    
    op1.push_back(ip[0]);
    op2.push_back((char)toupper(ip[0]));
    ip.erase(ip.begin());
    
    PermCapital(ip , op1);
    PermCapital(ip , op2);
    
}





int main() { 
    string ip;
    cin >>ip;
    
    string op = "";
    
    // op.push_back(ip[0]);
    // ip.erase(ip.begin() +0);
    
    // solve(ip , op);
    PermCapital(ip,op);
}
