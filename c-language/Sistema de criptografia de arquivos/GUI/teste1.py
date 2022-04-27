import kinterbasdb
import os
import bcrypt
import smtplib
import random
from email.mime.text import MIMEText

class User:
    def __init__(self):
        self.ID_USER = 0
        self.NOME = ''
        self.DATA_NASC = ''
        self.RECP = ''
        self.SENHA = ''
        self.EMAIL = ''
        self.CHAVE = ''
        self.DIV_BLOCO = ''
        self.P_CRIP = ''
        self.P_DESC = ''
        self.P_chave = ''
        self.P_iv = ''
        self.login = ''
        self.senha = ''
        self.lista_compartilhar = []

    def Cad_User(self):
        con = kinterbasdb.connect(dsn='Dados\DADOS.FDB', user='sysdba', password='102030')
        cur = con.cursor()
        SELECT = "SELECT NOME FROM USUARIOS WHERE NOME = '"+self.NOME+"'"
        cur.execute(SELECT)
        if (cur.fetchall()==[]):
            p = '4'
            arq = open('d.txt', 'w')
            arq.write(p)
            arq.close()
            os.system('TrueCipher.exe')
            arq = open('d.txt', 'r')
            texto = arq.read()
            arq.close()
            os.system('del d.txt')
            aux=[]
            aux=texto.split('\n')
            self.CHAVE = str(aux[0])
            self.DIV_BLOCO = str(aux[1])

            Senha = bcrypt.hashpw(self.SENHA, bcrypt.gensalt())
            self.P_CRIP = '%s\True\%s'%(os.path.dirname(os.path.realpath('True')),self.NOME)

            os.path.dirname (self.P_CRIP)
            if not os.path.exists (self.P_CRIP):
                os.mkdir ( self.P_CRIP )

            self.P_DESC = self.P_DESC+'\True'
            os.path.dirname (self.P_DESC)
            if not os.path.exists (self.P_DESC):
                os.mkdir ( self.P_DESC )

            self.P_DESC = self.P_DESC+'\True'+self.NOME

            os.path.dirname (self.P_DESC)
            if not os.path.exists (self.P_DESC):
                os.mkdir ( self.P_DESC )

            cur.execute("SELECT * FROM USUARIOS")
            cur.execute("INSERT INTO USUARIOS (ID_USER, NOME, DATA_NASC, RECP, EMAIL, SENHA, CHAVE, DIV_BLOCO, P_CRIP, P_DESC) VALUES (GEN_ID(GEN_USUARIOS_ID, 1),'"+self.NOME+"','"+self.DATA_NASC+"', '"+self.RECP+"','"+self.EMAIL+"','"+Senha+"','"+str(self.CHAVE)+"','"+str(self.DIV_BLOCO)+"','"+self.P_CRIP+"','"+self.P_DESC+"')")
            cur.execute("COMMIT")
            return 0
        else:
            return -1

    def val_login(self):
        con = kinterbasdb.connect(dsn='Dados\DADOS.FDB', user='sysdba', password='102030')
        cur = con.cursor()
        cur.execute("select ID_USER, NOME, SENHA, EMAIL, CHAVE, DIV_BLOCO, P_CRIP, P_DESC from USUARIOS where NOME = '"+self.login+"'")
        Dados_User=[]
        for Dados_User in cur:

            self.SENHA=str(Dados_User[2])

            if(bcrypt.hashpw(self.senha,self.SENHA) == self.SENHA):
                self.ID_USER = Dados_User[0]
                self.NOME = Dados_User[1]
                self.EMAIL = Dados_User[3]
                self.CHAVE = Dados_User[4]
                self.DIV_BLOCO = Dados_User[5]
                self.P_CRIP = Dados_User[6]
                self.P_DESC = Dados_User[7]
                cur.execute("SELECT ID_ENVIO, ID_RECB, NOME_ARQ, ATIVO FROM COMPARTILHAR WHERE ID_RECB = "+str(self.ID_USER)+" AND ATIVO = 1")
                self.lista_compartilhar = []
                aux1 = self.Busca_User()
                for aux in cur:
                    for i in aux1:
                        if(i[0]==aux[0]):
                            self.lista_compartilhar.append([str(i[1]),str(aux[1]),str(aux[2])])

                cur.execute("UPDATE COMPARTILHAR SET ATIVO = 0 WHERE ID_RECB = "+str(self.ID_USER))
                cur.execute ( "COMMIT" )
                return 0
            else:
                return 1
        if (Dados_User == []):
            return -1

    def Rec_Senha(self):
        con = kinterbasdb.connect(dsn='Dados\DADOS.FDB', user='sysdba', password='102030')
        cur = con.cursor()
        cur.execute("SELECT ID_USER, NOME, SENHA, EMAIL from USUARIOS where NOME = '"+self.login+"'")
        Dados=[]
        for i in cur:
            Dados=i
        self.EMAIL = str(Dados[3])
        self.NOME = str(Dados[1])

        Senha = random.randint(1,1000000)
        msg = 'Usuario: '+self.NOME + ' Nova Senha: ' + str(Senha)

        Senha = bcrypt.hashpw ( str(Senha) , bcrypt.gensalt ( ) )

        cur.execute("UPDATE USUARIOS SET SENHA = '"+str(Senha)+"' WHERE NOME = '"+self.login+"'")
        cur.execute('COMMIT')

        Email = self.EMAIL

        aux = Email.split('@')
        if(aux[1]=='gmail.com'):
            Para = self.EMAIL
            De = "douglassalazar.dcs@gmail.com"
            server = smtplib.SMTP( 'smtp.gmail.com', 587)
            server.ehlo()
            server.starttls()
            server.ehlo()
            server.login('truecipher.crip@gmail.com','true1020304050')
            mail = MIMEText(str(msg))
            mail['to'] = Para
            mail['from'] = De
            mail['Subject'] = 'Recuperacao Senha Tru Cypher'
            server.sendmail ( De , Para , mail.as_string() )
            server.quit( )
        elif aux[1]=='hotmail.com':
            Para = self.EMAIL
            De = "douglassalazar.dcs@gmail.com"
            server = smtplib.SMTP('smtp.live.com', 587 )
            server.ehlo()
            server.starttls()
            server.ehlo()
            server.login('truecipher.crip@gmail.com','true1020304050')
            mail = MIMEText ( str ( msg ) )
            mail['to'] = Para
            mail['from'] = De
            mail['Subject'] = 'Recuperacao Senha Tru Cypher'
            server.sendmail ( De , Para , mail.as_string ( ) )
            server.quit( )
        elif aux[1] == 'outlook.com':
            Para = self.EMAIL
            De = "douglassalazar.dcs@gmail.com"
            server = smtplib.SMTP( 'smtp.live.com', 587 )
            server.ehlo()
            server.starttls()
            server.ehlo()
            server.login('truecipher.crip@gmail.com','true1020304050')
            mail = MIMEText ( str ( msg ) )
            mail['to'] = Para
            mail['from'] = De
            mail['Subject'] = 'Recuperacao Senha Tru Cypher'
            server.sendmail ( De , Para , mail.as_string ( ) )
            server.quit( )
        elif aux[1] == 'yahoo.com.br':
            Para = self.EMAIL
            De = "douglassalazar.dcs@gmail.com"
            server = smtplib.SMTP( 'smtp.mail.yahoo.com',465 )
            server.ehlo()
            server.starttls()
            server.ehlo()
            server.login('truecipher.crip@gmail','true1020304050')
            mail = MIMEText ( str ( msg ) )
            mail['to'] = Para
            mail['from'] = De
            mail['Subject'] = 'Recuperacao Senha Tru Cypher'
            server.sendmail ( De , Para , mail.as_string ( ) )
            server.sendmail ( De , Para , msg )
            server.quit( )

    def Altera_Dados(self, cond):
        con = kinterbasdb.connect(dsn='Dados\DADOS.FDB', user='sysdba', password='102030')
        cur = con.cursor()
        cur.execute("SELECT NOME, SENHA, EMAIL,P_DESC  from USUARIOS where NOME = '"+self.login+"'")

        if cond == 1:
            cur.execute ( "UPDATE USUARIOS SET NOME = '" + str (self.NOME) + "' WHERE NOME = '" + self.login+ "'" )
            cur.execute ( 'COMMIT' )
            self.login=self.NOME
        elif cond == 2:
            Senha = bcrypt.hashpw(str(self.SENHA), bcrypt.gensalt())
            cur.execute ( "UPDATE USUARIOS SET SENHA = '" + str (Senha) + "' WHERE NOME = '" + self.login + "'" )
            cur.execute ( 'COMMIT' )
        elif cond == 3:
            cur.execute ( "UPDATE USUARIOS SET EMAIL = '" + str (self.EMAIL) + "' WHERE NOME = '" + self.login + "'" )
            cur.execute ( 'COMMIT' )

        elif cond == 4:
            cur.execute ( "UPDATE USUARIOS SET P_DESC = '" + str (self.P_DESC) + "' WHERE NOME = '" + self.login + "'" )
            cur.execute ( 'COMMIT' )

    def Criptografia(self, cond, Nome_Arq):
        if cond == 1:
            aux = Nome_Arq.split('\\')
            for i in aux:
                a = i

            Entrada = str(self.P_CRIP + '\\' + str(a))
            p='1\n' + str(Nome_Arq)+'\n'+ str(Entrada) + '\n' + str(self.DIV_BLOCO) + '\n' + str(self.CHAVE)
            arq = open('d.txt', 'w')
            arq.write(p)
            arq.close()
            os.system('TrueCipher.exe')

        elif cond == 2:
            aux = Nome_Arq.split('\\')
            for i in aux:
                a = i

            Entrada = str(self.P_DESC + '\\' + str(a))
            Nome_Arq = str(self.P_CRIP + '\\' +str(a))

            p='2\n' +str(Nome_Arq)+'\n'+ str(Entrada) + '\n' + str(self.DIV_BLOCO) + '\n' + str(self.CHAVE)
            arq = open('d.txt', 'w')
            arq.write(p)
            arq.close()
            os.system ( 'TrueCipher.exe' )

    def Busca_User(self):
        con = kinterbasdb.connect(dsn='Dados\DADOS.FDB', user='sysdba', password='102030')
        cur = con.cursor()
        cur.execute("SELECT ID_USER,NOME FROM USUARIOS")
        return cur.fetchall()

    def Compartilhar(self,ID_Aux, Nome_Arq):
        con = kinterbasdb.connect(dsn='Dados\DADOS.FDB', user='sysdba', password='102030')
        cur = con.cursor()

        aux = Nome_Arq.split ( '\\' )
        for i in aux:
            a = i
        Nome_Aux = str(a)

        cur.execute("SELECT ID_USER, P_CRIP, CHAVE, DIV_BLOCO FROM USUARIOS WHERE ID_USER = '"+str(ID_Aux)+"'")
        for Aux in cur:
            Dados =Aux
        cur.execute("SELECT * FROM COMPARTILHAR")
        cur.execute("INSERT INTO COMPARTILHAR(ID, ID_ENVIO, ID_RECB, NOME_ARQ, ATIVO) VALUES (GEN_ID(GEN_COMPARTILHAR_ID, 1),"+str(self.ID_USER)+","+str(ID_Aux)+",'"+str(Nome_Aux)+"',1)")
        cur.execute("COMMIT")

        Entrada = str(Dados[1]) + '\\' + Nome_Aux
        p = '3\n' + str ( Nome_Arq ) + '\n' + str ( Entrada ) + '\n' + str ( self.DIV_BLOCO ) + '\n' + str (self.CHAVE ) +'\n'+ str(Dados[2]) +'\n'+str(Dados[3])
        arq = open ( 'd.txt' , 'w' )
        arq.write ( p )
        arq.close ( )
        os.system ( 'TrueCipher.exe' )

