import pygtk
pygtk.require('2.0')
import gtk
import time
import os
from os import listdir
from os.path import isfile, join
import sys
import teste1
label_nome_user = gtk.Label()
label_email = gtk.Label()
labe_pdesc = gtk.Label()
usuario = teste1.User()

class spinner:

    def delete_event(self, widget, event, data=None):
        print "delete event occurred"
        return False

    def destroy(self, widget, data=None):
        print "destroy signal occurred"
        return False

    def make_spin (self):
        self.window2 = gtk.Window()
        self.window2.set_position(gtk.WIN_POS_CENTER_ALWAYS)
        self.window2.set_size_request(200, 100)
        self.window2.set_title('TrueCypher')
        self.window2.connect("delete_event", self.delete_event)
        self.window2.connect("destroy", self.destroy)
        self.window2.set_border_width(1)

        self.label = gtk.Label()

        self.fixed = gtk.Table(20,20)
        self.window2.add(self.fixed)
        self.fixed.attach(self.label, 0, 20, 0, 10)
        self.label.show()

        self.spinner = gtk.Spinner()
        self.fixed.attach(self.spinner, 0, 20, 10, 20)
        self.spinner.start()

        self.window2.show_all()

    def load(self, name):

        cond = usuario.Criptografia(1, name)
        if cond == 0:
            Dialog = gtk.MessageDialog()
            Dialog.set_markup("bem sucedido")
            Dialog.set_position(gtk.WIN_POS_CENTER)
            Dialog.show()

        if cond == 1:
            Dialog = gtk.MessageDialog()
            Dialog.set_markup("Erro no primeiro arquuivo")
            Dialog.set_position(gtk.WIN_POS_CENTER)
            Dialog.show()

        if cond == 2:
            Dialog = gtk.MessageDialog()
            Dialog.set_markup("Erro no segundo arquivo")
            Dialog.set_position(gtk.WIN_POS_CENTER)
            Dialog.show()

    def load_des (self, name):

        cond = usuario.Criptografia(2, name)

        if cond == 0:
            Dialog = gtk.MessageDialog()
            Dialog.set_markup("bem sucedido")
            Dialog.set_position(gtk.WIN_POS_CENTER)
            Dialog.show()

        if cond == 1:
            Dialog = gtk.MessageDialog()
            Dialog.set_markup("Erro no primeiro arquuivo")
            Dialog.set_position(gtk.WIN_POS_CENTER)
            Dialog.show()

        if cond == 2:
            Dialog = gtk.MessageDialog()
            Dialog.set_markup("Erro no segundo arquivo")
            Dialog.set_position(gtk.WIN_POS_CENTER)
            Dialog.show()

def compartilha(self, fixed2):
    window2 = gtk.Window()
    window2.set_size_request(500, 600)
    window2.set_title('Compartilhar')
    window2.set_border_width(1)

    fixed = gtk.Table(40, 40)
    window2.add(fixed)

    scrolled_window = gtk.ScrolledWindow()
    scrolled_window.set_usize(50, 50)
    fixed.attach(scrolled_window, 0, 20, 3, 37)
    scrolled_window.show()

    list = gtk.List()
    scrolled_window.add_with_viewport(list)

    lista_usuario = usuario.Busca_User()

    Rbutton = gtk.RadioButton(None, 'Selecione Usuario')
    Rbutton.set_size_request(256, 20)
    Rbutton.set_alignment(0, 0)
    Rbutton.connect("toggled", radio_toggle, lista_usuario[0][1])
    list_item = gtk.ListItem()
    list_item.add(Rbutton)
    list.add(list_item)
    i = 1
    for i in range(len(lista_usuario)-1):
        Rbutton = gtk.RadioButton(Rbutton, lista_usuario[i][1])
        Rbutton.set_size_request(256, 20)
        Rbutton.set_alignment(0, 0)
        Rbutton.connect("toggled", radio_toggle, lista_usuario[i][1])
        list_item = gtk.ListItem()
        list_item.add(Rbutton)
        list.add(list_item)

    scrolled_window = gtk.ScrolledWindow()
    scrolled_window.set_usize(50, 50)
    fixed.attach(scrolled_window, 20, 40, 3, 37)
    scrolled_window.show()

    list = gtk.List()
    scrolled_window.add_with_viewport(list)

    onlyfiles = [f for f in listdir(usuario.P_CRIP) if isfile(join(usuario.P_CRIP, f))]

    Cbutton = gtk.RadioButton(None, 'Selecione Arquivo')
    Cbutton.set_size_request(256, 20)
    Cbutton.set_alignment(0, 0)
    Cbutton.connect("toggled", check_toggle, onlyfiles[0])
    list_item = gtk.ListItem()
    list_item.add(Cbutton)
    list.add(list_item)
    i=1
    for i in range(len(onlyfiles)):
        Cbutton = gtk.RadioButton(Cbutton, onlyfiles[i])
        Cbutton.set_size_request(256, 20)
        Cbutton.set_alignment(0, 0)
        Cbutton.connect("toggled", check_toggle, onlyfiles[i])
        list_item = gtk.ListItem()
        list_item.add(Cbutton)
        list.add(list_item)


    label = gtk.Label("Usuarios")
    fixed.attach(label, 0, 20, 0, 3)

    label = gtk.Label("Arquivos")
    fixed.attach(label, 20, 40, 0, 3)

    separa = gtk.VSeparator()
    fixed.attach(separa, 19, 21, 0, 3)

    self.button = gtk.Button("Compartilhar")
    self.button.connect("clicked", compartilha_controle, Rbutton, Cbutton, lista_usuario)
    fixed.attach(self.button, 0, 40, 38, 40)

    window2.show_all()

def radio_toggle(self, clicked):
    global nome
    nome = clicked
    clicked = None

def check_toggle(self, clicked):
    global arquivo
    arquivo = clicked
    clicked = None

def compartilha_controle(self, Rbutton, Cbutton, lista_usuario):

    for i in lista_usuario:
        if i[1] == nome :
            id_nome = i[0]
            break


    usuario.Compartilhar(int(id_nome), usuario.P_CRIP +'\\'+arquivo)

############################ TROCAR SENHA ############################################
def trocar_senha(self, fixed2):
    window2 = gtk.Window()
    window2.set_position(gtk.WIN_POS_CENTER_ALWAYS)
    window2.set_size_request(400, 100)
    window2.set_title('Trocar Senha')
    window2.set_border_width(1)

    fixed = gtk.Table(40, 40)
    window2.add(fixed)

    label = gtk.Label('Senha atual')
    fixed.attach(label,0, 5, 0, 10)
    label = gtk.Label('Nova senha')
    fixed.attach(label, 0, 5, 10, 20)
    label = gtk.Label('Confirmar senha')
    fixed.attach(label, 0, 5, 20, 30)

    atual = gtk.Entry()
    atual.set_visibility(False)
    atual.set_invisible_char("*")
    fixed.attach(atual, 5, 35, 0, 10)
    nova = gtk.Entry()
    nova.set_visibility(False)
    nova.set_invisible_char("*")
    fixed.attach(nova, 5, 35, 10, 20)
    confir = gtk.Entry()
    confir.set_visibility(False)
    confir.set_invisible_char("*")
    fixed.attach(confir, 5, 35, 20, 30)

    button = gtk.Button('Trocar')
    button.connect("clicked", esqueci_minha_senha, window2, atual, nova, confir)
    fixed.attach(button, 5, 35, 30, 40)

    window2.show_all()

def esqueci_minha_senha(self, window, atual1, nova1, confir1):
    atual = atual1.get_text()
    nova = nova1.get_text()
    confir = confir1.get_text()

    if atual == usuario.senha and nova == confir:
        usuario.SENHA = nova
        usuario.Altera_Dados(2)
        window.destroy()
    else :
        window.destroy()

############################ TROCAR EMAIL ############################################
def trocar_email(self, fixed2):
    window2 = gtk.Window()
    window2.set_position(gtk.WIN_POS_CENTER_ALWAYS)
    window2.set_size_request(400, 100)
    window2.set_title('Trocar Email')
    window2.set_border_width(1)

    fixed = gtk.Table(40, 30)
    window2.add(fixed)


    label = gtk.Label('Nova email')
    fixed.attach(label, 0, 5, 0, 10)
    label = gtk.Label('Confirmar email')
    fixed.attach(label, 0, 5, 10, 20)

    nova = gtk.Entry()
    fixed.attach(nova, 5, 35, 0, 10)
    confir = gtk.Entry()
    fixed.attach(confir, 5, 35, 10, 20)

    button = gtk.Button('Trocar')
    button.connect("clicked", troca_email_aux, window2, nova, confir, fixed2)
    fixed.attach(button, 5, 35, 20, 30)

    window2.show_all()

def troca_email_aux(self, window, nova1, confir1, fixed2):

    nova = nova1.get_text()
    confir = confir1.get_text()

    if  nova == confir:
        usuario.EMAIL = nova
        usuario.Altera_Dados(3)
        put_label(self, fixed2)
        window.destroy()
    else :
        window.destroy()


def esqueci_minha_senha_aux(self, window, nome):
    usuario.login = nome.get_text()
    usuario.Rec_Senha()
    window.destroy()

################################ ARq folder ##########################################
def arq_folder(self, fixed2):
    dialog = gtk.FileChooserDialog("Open..",
                                   None,
                                   gtk.FILE_CHOOSER_ACTION_SELECT_FOLDER,
                                   (gtk.STOCK_CANCEL, gtk.RESPONSE_CANCEL,
                                    gtk.STOCK_OK, gtk.RESPONSE_OK))

    dialog.set_action(gtk.FILE_CHOOSER_ACTION_SELECT_FOLDER)
    dialog.set_default_response(gtk.RESPONSE_OK)
    response = dialog.run()
    if response == gtk.RESPONSE_OK:
        filename = dialog.get_filename()
    dialog.destroy()
    usuario.P_DESC = filename
    usuario.Altera_Dados(4)
    put_label(self, fixed2)
    return True

def cadastrar_novo_user(self, window, fixed, nome, email, senha, confirmar, palavra, data):

    usuario.NOME = nome.get_text()
    usuario.DATA_NASC = data.get_text()
    usuario.RECP = palavra.get_text()
    usuario.EMAIL = email.get_text()
    usuario.P_DESC = os.path.dirname("./Decifrados")

    if (senha.get_text() == confirmar.get_text()):
        usuario.SENHA = senha.get_text()
        if usuario.Cad_User()==0:
            Dialog = gtk.MessageDialog()
            Dialog.set_markup("Cadastro bem sucedido")
            Dialog.set_position(gtk.WIN_POS_CENTER)
            Dialog.show()
            window.destroy()

        else:
            Dialog = gtk.MessageDialog()
            Dialog.set_markup("Cadastro mal sucedido")
            Dialog.set_position(gtk.WIN_POS_CENTER)
            Dialog.show()

    else:
        label = gtk.Label("Senhas nao conferem")
        fixed.attach(label, 0, 100, 80, 85)
        window.show_all()
        return

def put_label(self, fixed):
    label_nome_user.set_text(usuario.NOME)
    label_email.set_text(usuario.EMAIL)
    labe_pdesc.set_text(usuario.P_DESC)

    fixed.attach(label_nome_user, 91, 110, 25, 30)
    fixed.attach(label_email, 91, 110, 30, 35)
    fixed.attach(labe_pdesc, 91, 110, 35, 40)
    fixed.show_all()

def troca_pasta (self, fixed2):

    window2 = gtk.Window()
    window2.set_position(gtk.WIN_POS_CENTER_ALWAYS)
    window2.set_size_request(400, 100)
    window2.set_title('Escolha uma opcao')
    window2.set_border_width(1)

    fixed = gtk.Table(20, 30)
    window2.add(fixed)


    button = gtk.Button("TROCAR EMAIL")
    button.connect("clicked", trocar_email, fixed2)
    fixed.attach(button, 0, 20, 20, 30)

    button = gtk.Button("TROCAR DIRETORIO 'DESCRIPTOGRAFADOS'")
    button.connect("clicked", arq_folder, fixed2)
    fixed.attach(button, 0, 20, 10, 20)

    button = gtk.Button("TROCAR SENHA")
    button.connect("clicked", trocar_senha, fixed2)
    fixed.attach(button, 0, 20, 0, 10)

    window2.show_all()

