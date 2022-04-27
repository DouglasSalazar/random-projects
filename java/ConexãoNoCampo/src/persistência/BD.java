package persistência;
import java.sql.Connection; 
import java.sql.DriverManager; 
import java.sql.ResultSet; 
import java.sql.SQLException; 
import java.sql.Statement;

public class BD {
    static final String URL_BD = "jdbc:mysql://localhost/dados";
    static final String USUARIO = "root";
    static final String SENHA = "root";
    public static Connection conexão = null;

    public static void criaConexão(){
        try{
            conexão = DriverManager.getConnection(URL_BD, USUARIO, SENHA);
        }catch(SQLException exceção_sql){exceção_sql.printStackTrace();}
    }
    
    public static void fechaConexão(){
        try{
            conexão.close();
        }catch(SQLException exceção_sql){exceção_sql.printStackTrace();}
    }
}
