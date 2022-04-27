//
//Usar o símbolo & no lugar de entrada vazia (epson)
//

typedef string TAlfa;
//typedef string *TEstados;
typedef string TEstados;
typedef string **TDelta;

const bool NAO_MARCADO=false;
const bool MARCADO=true;
const int NAO_TEM=-1;

struct TAutomato{
TEstados Q;
TAlfa A;
TDelta trans;
TEstados qo;
TEstados F;
};

struct TEstadoD{
    string T;
    bool marca;
}

TAutomato N,D;
TEstadoD EstadoD; //no pior caso terá tamanho 2^|N.Q|

void constrSubconjuntos()
{   string U,subQ;
    int t=0,d=0;
    fechamentoE(U,N.q0);//U=fechamentoE(N.qo)

    EstadoD[d].T=U;
    EstatoD[d].marca=NAO_MARCADO;

    while ((EstadoD[t].marca==NAO_MARCADO) && (t <= d)) {
        EstadoD[t].marca=MARCADO;
        //para cada delta(T,a)
        for(int a=0;a<N.Alfabeto.length();a++){
            movimento(subQ,EstadoD[t].T,A[a]);//subQ=movimento(T,a)
            fechamentoE(U,subQ);  //U=fechamentoE(movimento(EstadoD[t].T,a))

            if (!inEstadoD(U)){ //se U nao está em EstadoD
                  d++;
                  EstadoD[d].T=U; //insere
                  EstadoD[d].marca=NAO_MARCADO;
            }
            D.trans[t][a]=U;
        } //for
        t++;
    }//while
}


//mostra os estados do afd como <1,2,3>,<3,4>,<2,3,4>
string MostraEstados(string  conjEstados)
{ string estadoDet;
  estadoDet="<"+conjEstados[0];
  for(int i=1; i<conjEstados.length();i++)
  {
      estadoDet=estadoDet+","+conjEstados[i];
  }
  estadoDet=estadoDet+">";
  return estadoDet;
}

void fechamentoE(string fechoE,string T)
{
    string pilha=T;//se quiser usar tipo stack (tem vector, list, stack)
    string U="";
    //int t;

    fechoE=T; //o fecho é pelo menos o proprio estado
    topo=pilha.length()-1;

    while(pilha.length() > 0 ){  //pilha # vazia
        q=pilha.back(); //pega ultimo elemento
        pilha.pop_back();//desempilha do topo
        //topo--; //a posicao do topo diminui
        t=pos(q,N.Q); //posicao elemento q no conjunto Q
        U=N.trans[t][N.A.length()-1];//pega N.delta(q,Epson)
        //para cada estado u de U com um lado t para u rotulado epson
        //   _   &    _
        //  [t]----->[u]    u=delta(t,&)
        //
        for(int u=0;u<U.length();u++){
            if (!pertence(U[u],fechoE)){ //se não está em fechoE
                fechoE.push_back(U[u]);//adiciona ao resultado final

                pilha.push_back(U[u]); //coloca na pilha
                //topo++; //a posicao do topo sobe
            } //if
        }//for
    }//while
    sort(fechoE);//ordena os estados SE NAO FUNCIONAR IMPLEMENTAR
}

void movimento(string p, string S, char c )
{
    int a,q;
    string p="";
    a=pos(c,N.A);//acha a posicao do simbolo c no conjunto A

    //para cada s=S[i] de S
    for(int i=0;i<S.length();i++){
        q=pos(S[i],N.Q); //acha a posicao de S[i] no conjunto Q
        p=p.push_back(N.trans[q][a]);//adiciona em p N.Delta(s,c)
    }
    sort(p);//ordena os estados SE NAO FUNCIONAR IMPLEMENTAR
}

bool inEstadoD(string s)
{
   for(int i=0;i<EstadoD.length();i++)
       if(s==EstadoD[i]) return true;
   return false;
}

bool pertence(char s, string S)
{
    if (pos(s,S)>=0)
       return true;
    return false;
}

int pos(char s, string S)
{
    int i;
    for(i=0;i<S.length();i++)
       if(S[i]==s) return i;
    return NAO_TEM;
}

void splitToken(string *token,string S, char sep)
{   int k=0;
    int ntk=0;
    string aux="";

    for(int i=0;i<S.length()){
        if(S[i]==sep) ntk++;

    token=new[ntk+1];//aloca ntk vetores string
    k=0;
    for(int i=0;i<S.length()){

        if(S[i]!=sep && S[i]!= ' ') aux=aux+S[i];
        else {
           token[k]=aux;
           aux="";
           k++;
        }
    }
}

