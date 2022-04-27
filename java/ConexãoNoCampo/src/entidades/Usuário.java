package entidades;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException; 
import java.util.Vector; 
import persistência.BD;

public class Usuário {

    
    private int ID;
    private String nome;
    private String CPF;
    private String profissão;
    private String email;

    
    public Usuário(int ID, String nome, String CPF, String profissão, String email){
        this.ID = ID;
        this.nome = nome;
        this.CPF = CPF;
        this.profissão = profissão;
        this.email = email;
    }
    
    public int getID(){
        return ID;
    }
    
    public void setID(int ID){
        this.ID = ID;
    }
    
    public String getNome(){
        return nome;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    public String getCPF(){
        return CPF;
    }
    
    public void setCPF(String CPF){
        this.CPF = CPF;
    }
    
    public String getProfissão(){
        return profissão;
    }
    
    public void setProfissão(String profissão){
        this.profissão = profissão;
    }
    
    public String getEmail(){
        return email;
    }
    
    public void setEmail(String email){
        this.email = email;
    }
    
    public Visão<String> getVisão () {        
        return new Visão<String>(String.valueOf(ID),String.valueOf(nome));    
    }
    
    public static String inserirUsuário(Usuário usuario){
        String sql = "INSERT INTO usuário (Nome,CPF,Profissão,Email) " + "VALUES (?, ?, ?, ?)";
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, usuario.getNome());
            comando.setString(2, usuario.getCPF());
            comando.setString(3, usuario.getProfissão());
            comando.setString(4, usuario.getEmail());
            comando.executeUpdate();
            comando.close();
            return null;
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
            return "Erro na Inserção do Usuário no Banco!";
        }
    }
    
    public static String alterarUsuário(Usuário usuario){
        String sql = "UPDATE usuário SET Nome = ?,Profissão  = ?,Email  = ? " + "WHERE CPF = ?";
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, usuario.getNome());
            comando.setString(2, usuario.getProfissão());
            comando.setString(3, usuario.getEmail());
            comando.setString(4, usuario.getCPF());
            comando.executeUpdate();
            comando.close();
            return null;
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
            return "Erro na alteração do Usuário no Banco!";
        }
    }
    
    public static String removerUsuário(Usuário usuario){
        String sql = "DELETE FROM usuário " + "WHERE CPF = ?";
        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, usuario.getCPF());
            comando.executeUpdate();
            comando.close();
            return null;
        }catch (SQLException exceção_sql){
            exceção_sql.printStackTrace();
            return "Erro na Remoção do Usuário do Banco!";
        }
    }
    
    public static Usuário buscaUsuario(String cpf){
        String sql = "SELECT ID, Nome, CPF, Profissão,Email FROM usuário"+" WHERE CPF = ?";
        ResultSet list_resultados = null;
        Usuário usuario = null;

        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1,cpf);
            list_resultados = comando.executeQuery();
            while(list_resultados.next()){

                usuario = new Usuário(list_resultados.getInt("ID"),
                        list_resultados.getString("Nome"),
                        cpf,
                        list_resultados.getString("Profissão"),
                        list_resultados.getString("Email")
                    );
            }
            
            if (usuario == null) return null;
            
        }catch(SQLException exceção_sql){
            exceção_sql.printStackTrace();
            usuario = null;
        }
        return usuario;
    }
    
    public static Visão<String> buscarNome(String ID){
        String sql = "SELECT ID, Nome FROM usuário"+" WHERE ID = ?";
        ResultSet list_resultados = null;
        Visão<String> visões = null;  

        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1,ID);
            list_resultados = comando.executeQuery();
            while(list_resultados.next()){

                visões = new Visão<String> (list_resultados.getString("ID"),
                        list_resultados.getString("Nome")
                    );
            }
            
            if (visões == null) return null;
            
        }catch(SQLException exceção_sql){
            exceção_sql.printStackTrace();
            visões = null;
        }
        return visões;
    }
    public static Vector <Usuário> buscaUsuarioList(){
        String sql = "SELECT * FROM usuário";
        ResultSet list_resultados = null;
        Vector <Usuário> usuario = new Vector();

        try{
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            list_resultados = comando.executeQuery();
            while(list_resultados.next()){
                usuario.add(new Usuário(list_resultados.getInt("ID"),
                        list_resultados.getString("Nome"),
                        list_resultados.getString("CPF"),
                        list_resultados.getString("Profissão"),
                        list_resultados.getString("Email")
                    ));
            }
            
        }catch(SQLException exceção_sql){
            exceção_sql.printStackTrace();
            usuario = null;
        }
        return usuario;
    }
    public static Vector <Visão<String>> getVisões () {        
         String sql = "SELECT ID, Nome FROM usuário";        
         ResultSet lista_resultados = null;        
         Vector<Visão<String>> visões = new Vector();        
         String id;        
         try {            
             PreparedStatement comando = BD.conexão.prepareStatement(sql);            
             lista_resultados = comando.executeQuery();            
             while (lista_resultados.next()) {                
                 id = lista_resultados.getString("ID");                
                 visões.addElement(new Visão<String> (id,                     
                         lista_resultados.getString("Nome")));            
            }                         
            lista_resultados.close();            
            comando.close();        
         } catch (SQLException exceção_sql) {exceção_sql.printStackTrace ();}        
         return visões;    
     }
    public String toString(){
        return "ID: " + this.ID + "\nNome: " + this.nome + "\nCPF: " + this.CPF + "\nProfissão: " + this.profissão + "\nEmail: " + this.email;
    }
    
}
