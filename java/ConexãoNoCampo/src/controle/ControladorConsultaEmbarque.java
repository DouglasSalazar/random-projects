
package controle;
import entidades.Embarque;
import interfaces.JanelaConsultaEmbarque;

public class ControladorConsultaEmbarque {
    public ControladorConsultaEmbarque(){
        new JanelaConsultaEmbarque(this).setVisible(true);
    }
}
