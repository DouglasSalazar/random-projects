/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controle;
import entidades.Usuário;
import interfaces.JanelaCadastroUsuário;
/**
 *
 * @author Douglas
 */
public class ControladorCadastroUsuário {
    public ControladorCadastroUsuário(){
        new JanelaCadastroUsuário(this).setVisible(true);
    }
    
    public String inserirUsuário(Usuário usuario){
        Usuário usuario1 = Usuário.buscaUsuario(usuario.getCPF());
        if(usuario1 == null){
            return Usuário.inserirUsuário(usuario);
        }else{
            return "CPF de usuário já cadastrado";
        }
    }
    
    public String alterarUsuário(Usuário usuario){
        Usuário usuario1 = Usuário.buscaUsuario(usuario.getCPF());
        if(usuario1 != null){
            return Usuário.alterarUsuário(usuario);
        }else{
            return "CPF de usuário não cadastrado";
        }
    }
    
    public String removerUsuário(Usuário usuario){
        Usuário usuario1 = Usuário.buscaUsuario(usuario.getCPF());
        if(usuario1 != null){
            return Usuário.removerUsuário(usuario);
        }else{
            return "CPF de usuário não cadastrado";
        }
    }
    
}
