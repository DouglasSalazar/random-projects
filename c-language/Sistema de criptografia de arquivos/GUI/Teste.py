import add1
import cypher_control
import pygtk
pygtk.require('2.0')
import gtk
import os
import teste1
from os import listdir
from os.path import isfile, join
# Variaveis globais
arquivo = None
rbutton = gtk.RadioButton()
label_nome = gtk.Label()
label_tamanho = gtk.Label()
label_status = gtk.Label()
spin = cypher_control.spinner()

class HelloWorld:
########################Construcao da janela de arquivos cifrados ##########################

    def busca_nomes(self, text):
        files = [f for f in listdir(cypher_control.usuario.P_CRIP) if isfile(join(cypher_control.usuario.P_CRIP, f))]

        for i in range(0, len(files)):
            if text in files[i]:
                self.radio_response(None, files[i])

    def radio_response2(self, fixed, scrolled):

        onlyfiles = [f for f in listdir(cypher_control.usuario.P_CRIP) if isfile(join(cypher_control.usuario.P_CRIP, f))]
        self.boxH = gtk.HBox(False, 5)
        self.scrolled_window.add_with_viewport(self.boxH)
        self.list = gtk.List()
        self.boxH.pack_start(self.list, False, False, 0)

        for i in range(len(onlyfiles)):
            if (i == len(onlyfiles)/2):
                self.list = gtk.List()
                self.boxH.pack_start(self.list, False, False, 0)

            nome = onlyfiles[i]
            button = gtk.Button(nome)
            button.set_size_request(256, 20)
            button.set_alignment(0, 0)
            list_item = gtk.ListItem()
            list_item.add(button)
            self.list.add(list_item)
            string = button.get_label()
            button.set_tooltip_text(string)
            button.connect("clicked", self.radio_response, string)


        self.boxH.show_all()

    def radio_response(self, aux, data):
        arquivo = open(cypher_control.usuario.P_CRIP+"\\"+data, "r")
        self.THE_FILE  = cypher_control.usuario.P_CRIP+"\\" + data

        if arquivo != None:
            nomedoarquivo = data.split("\\")
            label_nome.set_text(nomedoarquivo[len(nomedoarquivo) - 1])
            label_tamanho.set_text(str(os.path.getsize(cypher_control.usuario.P_CRIP+"\\"+data) / 1000) + " KBytes")
            label_status.set_text("Cifrado")
        arquivo.close()

    def list_get_name(self, gtklist, data):
        dlist = gtklist.get_selection()
        for item in dlist:
            item_data_string = item.get_data("list_item_data")
            self.radio_response(item_data_string)

########################Fim  da janela de arquivos cifrados ##########################
########################Criacao de selecionador de arquivos ##########################

    def arq(self, widget, data=None):
        dialog = gtk.FileChooserDialog("Open..",
                                       None,
                                       gtk.FILE_CHOOSER_ACTION_OPEN,
                                       (gtk.STOCK_CANCEL, gtk.RESPONSE_CANCEL,
                                       gtk.STOCK_OPEN, gtk.RESPONSE_OK))


        dialog.set_default_response(gtk.RESPONSE_OK)
        response = dialog.run()
        if response == gtk.RESPONSE_OK :
            filename = dialog.get_filename()
            arquivo = open(filename, "r")
            self.THE_FILE = filename
            if arquivo != None :
                nomedoarquivo = filename.split("\\")
                label_nome.set_text(nomedoarquivo[len(nomedoarquivo) - 1])
                label_tamanho.set_text(str(os.path.getsize(filename)/1000)+" KBytes")
                if cypher_control.usuario.P_CRIP not in filename:
                    label_status.set_text("Decifrado")
                else:
                    label_status.set_text("Cifrado")

            arquivo.close()
        dialog.destroy()

########################Fim  da janela de selecao de arquivos ########################

#####################Construcao da janela de arquivos decifrados #####################

    def busca_nomes_aux(self, text):
        files = [f for f in listdir(cypher_control.usuario.P_DESC) if isfile(join(cypher_control.usuario.P_DESC, f))]

        for i in range(0, len(files)):
            if text in files[i]:
                self.radio_response_aux(None, files[i])

    def radio_response2_aux(self, fixed, scrolled):
        onlyfiles = [f for f in listdir(cypher_control.usuario.P_DESC) if isfile(join(cypher_control.usuario.P_DESC, f))]

        self.boxH = gtk.HBox(False, 5)
        self.scrolled_window2.add_with_viewport(self.boxH)
        self.list = gtk.List()
        self.boxH.pack_start(self.list, False, False, 0)

        for i in range(len(onlyfiles)):
            if (i == len(onlyfiles)/2):
                self.list = gtk.List()
                self.boxH.pack_start(self.list, False, False, 0)

            nome = onlyfiles[i]
            button = gtk.Button(nome)
            button.set_size_request(256, 20)
            button.set_alignment(0, 0)
            list_item = gtk.ListItem()
            list_item.add(button)
            self.list.add(list_item)
            string = button.get_label()
            button.set_tooltip_text(string)
            button.connect("clicked", self.radio_response_aux, string)


        self.boxH.show_all()

    def radio_response_aux(self, aux, data):
        arquivo = open(cypher_control.usuario.P_DESC+"\\" + data, "r")
        self.THE_FILE  = cypher_control.usuario.P_DESC+"\\" + data
        if arquivo != None:
            nomedoarquivo = data.split("\\")
            label_nome.set_text(nomedoarquivo[len(nomedoarquivo) - 1])
            label_tamanho.set_text(str(os.path.getsize(cypher_control.usuario.P_DESC+"\\" + data) / 1000) + " KBytes")
            label_status.set_text("Decifrado")
        arquivo.close()

    def list_get_name_aux(self, gtklist, data):
        dlist = gtklist.get_selection()
        for item in dlist:
            item_data_string = item.get_data("list_item_data")
            self.radio_response_aux(item_data_string)


########################### fim  da janela de arquivos decifrados#################

#Funcoes de destruicao de widget

    def delete_event(self, widget, event, data=None):
        print "delete event occurred"
        return False

    def destroy(self, widget, data=None):
        print "destroy signal occurred"
        gtk.main_quit()

# funcao de cifragem de arquivo
    def cifrar(self, widget, fixed, data):
        spin.load(self.THE_FILE)
        self.scrolled_window.destroy()
        self.scrolled_window = gtk.ScrolledWindow()
        self.scrolled_window.set_usize(250, 250)
        self.fixed.attach(self.scrolled_window, 0, 50, 70, 120)
        self.scrolled_window.show()
        self.radio_response2(self.fixed,self.scrolled_window)

    # funcao de decifragem de arquivo


    def decifrar(self, widget, fixed, data):
        spin.load_des(self.THE_FILE)
        os.remove(self.THE_FILE)

        self.scrolled_window2.destroy()
        self.scrolled_window2 = gtk.ScrolledWindow()
        self.scrolled_window2.set_usize(250, 250)
        self.fixed.attach(self.scrolled_window2, 73, 120, 70, 120)
        self.scrolled_window2.show()
        self.radio_response2_aux(self.fixed, self.scrolled_window2)

        self.scrolled_window.destroy()
        self.scrolled_window = gtk.ScrolledWindow()
        self.scrolled_window.set_usize(250, 250)
        self.fixed.attach(self.scrolled_window, 0, 50, 70, 120)
        self.scrolled_window.show()
        self.radio_response2(self.fixed, self.scrolled_window)

    def busca(self, widget, fixed, data, entry):
        text = entry.get_text()
        self.busca_nomes(text)

    def busca_aux(self, widget, fixed, data, entry2):
        text2 = entry2.get_text()
        self.busca_nomes_aux(text2)

    def controle_log(self, func, window, login, senha):

        cypher_control.usuario.senha = senha.get_text()
        cypher_control.usuario.login = login.get_text()
        condicao = cypher_control.usuario.val_login()

        if  condicao == 0:
            self.inicio()
            window.hide()

        if  condicao == -1:
            Dialog = gtk.MessageDialog()
            Dialog.set_markup("Usuario nao cadastrado")
            Dialog.set_position(gtk.WIN_POS_CENTER)
            Dialog.show()

        if  condicao == 1:
            Dialog = gtk.MessageDialog()
            Dialog.set_markup("Usuario ou/e senha incorretos")
            Dialog.set_position(gtk.WIN_POS_CENTER)
            Dialog.show()

    def inicio(self):
        self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        self.window.set_size_request(1000, 500)
        self.window.maximize()
        self.window.set_title('TrueCypher')
        self.window.connect("delete_event", self.delete_event)
        self.window.connect("destroy", self.destroy)
        self.window.set_border_width(1)

        # cria novo fixed
        self.fixed = gtk.Table(120, 120, True)
        self.window.add(self.fixed)
        self.fixed.show()

        self.scrolled_window = gtk.ScrolledWindow()
        self.scrolled_window.set_usize(250, 250)
        self.fixed.attach(self.scrolled_window, 0, 50, 70, 120)
        self.scrolled_window.show()

        self.scrolled_window2 = gtk.ScrolledWindow()
        self.scrolled_window2.set_usize(250, 250)
        self.fixed.attach(self.scrolled_window2, 73, 120, 70, 120)
        self.scrolled_window2.show()

        self.entry = gtk.Entry(max=0)

        self.fixed.attach(self.entry, 14, 45, 65, 70)
        self.entry.show()

        self.entry2 = gtk.Entry(max=0)

        self.fixed.attach(self.entry2, 89, 115, 65, 70)
        self.entry2.show()

        self.button = gtk.Button()
        self.button.props.relief = gtk.RELIEF_NONE
        self.button.connect("clicked", self.busca, self.fixed, self.button, self.entry)
        self.button.set_usize(22, 22)
        image = gtk.image_new_from_file('Imagens\search.jpg')
        self.button.add(image)
        image.show()
        self.fixed.attach(self.button, 45, 50, 65, 70)
        self.button.show()

        self.button = gtk.Button()
        self.button.props.relief = gtk.RELIEF_NONE
        self.button.connect("clicked", self.busca_aux, self.fixed, self.button, self.entry2)
        self.button.set_usize(22, 22)
        image = gtk.image_new_from_file('Imagens\search.jpg')
        self.button.add(image)
        image.show()
        self.fixed.attach(self.button, 115, 120, 65, 70)
        self.button.show()

        # cria imagems
        add1.put_images(self.fixed)

        # cria botoes
        add1.put_buttons(self, self.fixed, self.window, self.arq, self.cifrar, self.decifrar)

        # Create a Frame
        add1.put_labels(self, self.fixed, self.radio_response2, label_nome, label_tamanho, label_status,
                        self.scrolled_window,
                        self.scrolled_window2, self.radio_response2_aux)

        # and the window
        self.window.show_all()

        if cypher_control.usuario.lista_compartilhar != []:

            self.window3 = gtk.Window()
            self.window3.set_position(gtk.WIN_POS_CENTER_ALWAYS)
            self.window3.set_size_request(400, 150)
            self.window3.set_title('Compartilharam com voce')
            self.window3.set_border_width(1)

            # cria novo fixed
            self.fixed2 = gtk.Table(20, 20, True)
            self.window3.add(self.fixed2)
            self.fixed2.show()
            string = ''
            for i in cypher_control.usuario.lista_compartilhar:
                string = string + i[0] + "  Compartilhou  " + i[2] + ", \n"

            self.label = gtk.Label(string)
            self.fixed2.attach(self.label, 0, 20, 0, 20)

            self.window3.show_all()

    def __init__(self):

        self.THE_FILE = ""
        self.window2 = gtk.Window(gtk.WINDOW_TOPLEVEL)
        self.window2.set_size_request(1000, 500)
        self.window2.maximize()
        self.window2.set_title('TrueCypher')
        self.window2.connect("delete_event", self.delete_event)
        self.window2.connect("destroy", self.destroy)
        self.window2.set_border_width(1)

        fixed = gtk.Table(120, 120, True)
        self.window2.add(fixed)
        fixed.show()

        entry = gtk.Entry(max=0)
        fixed.attach(entry, 50, 80, 62, 67)
        entry.show()
        entry2 = gtk.Entry(max=0)
        fixed.attach(entry2, 50, 80, 68, 73)
        entry2.set_visibility(False)
        entry2.set_invisible_char("*")
        entry2.show()

        button = gtk.Button()
        button.props.relief = gtk.RELIEF_NONE
        button.connect("clicked", self.controle_log, self.window2, entry, entry2)
        button.set_usize(380, 90)
        image = gtk.image_new_from_file('Imagens\Login.jpg')
        button.add(image)
        image.show()
        fixed.attach(button, 40, 80, 80, 100)
        button.show()

        button = gtk.Button()
        self.image = gtk.image_new_from_file('Imagens\Esqueceu.jpg')
        button.add(self.image)
        button.props.relief = gtk.RELIEF_NONE
        button.connect("clicked", add1.controle_esquecisenha)
        button.set_usize(100, 20)
        fixed.attach(button, 40, 60, 100, 104)
        button.show()

        button = gtk.Button()
        self.image = gtk.image_new_from_file('Imagens\Cadastre-se.jpg')
        button.add(self.image)
        button.props.relief = gtk.RELIEF_NONE
        button.connect("clicked", add1.controle_cadastro)
        button.set_usize(100, 20)
        fixed.attach(button, 60, 80, 100, 104)
        button.show()


        label = gtk.Label("Nome ou Email")
        label.set_alignment(0,0)
        fixed.attach(label, 40, 50, 62, 67)
        label.set_alignment(0,0)
        label = gtk.Label("Senha")
        fixed.attach(label, 42, 50, 68, 73)

        image = gtk.image_new_from_file('Imagens\peril.png')
        image.show()
        fixed.attach(image, 40, 80, 15, 60)
        self.window2.show_all()


    def main(self):
        gtk.main()


if __name__ == "__main__":
    hello = HelloWorld()
    hello.main()