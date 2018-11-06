<?php
	class ControlSondage extends CI_Controller {
    public function __construct(){
      parent::__construct();
      $this->load->library('form_validation');
    }
		public function index() {
      $this->form_validation->set_rules('titre','Titre','required');
      $this->form_validation->set_rules('lieu','Lieu','required');
      if (isset($_POST['envoi'])==FALSE) {
        if(isset($_POST['plusjour'])){
          $pff = $this->input->post();
          $this->session->set_userdata('lieu',$pff['lieu']);
          $this->session->set_userdata('titre',$pff['titre']);
          $this->session->set_userdata('desc',$pff['desc']);
          $date = $this->session->userdata('compteurDate');
          for($p=1;$p<=$date;$p++){
            $this->session->set_userdata('date_'.$p,$pff['date_'.$p]);
            for($v=1;$v<=$this->session->userdata('compteur_'.$p);$v++){
              $this->session->set_userdata('heure_'.$p.$v,$pff['heure_'.$p.$v]);
            }
          }
          $date++;
          $this->session->set_userdata('compteurDate',$date);
          $this->session->set_userdata('compteur_'.$date,1);
        }
        if(isset($_POST['moinsjour'])){
          $date = $this->session->userdata('compteurDate');
          if($date>1){
            $pff = $this->input->post();
            $this->session->set_userdata('lieu',$pff['lieu']);
            $this->session->set_userdata('titre',$pff['titre']);
            $this->session->set_userdata('desc',$pff['desc']);
            for($p=1;$p<=$date;$p++){
              $this->session->set_userdata('date_'.$p,$pff['date_'.$p]);
              for($v=1;$v<=$this->session->userdata('compteur_'.$p);$v++){
                $this->session->set_userdata('heure_'.$p.$v,$pff['heure_'.$p.$v]);
              }
            }
            for($v=1;$v<=$this->session->userdata('compteur_'.$date);$v++){
              $this->session->unset_userdata('heure_'.$date.$v);
            }
            $this->session->unset_userdata('date_'.$date);
            $this->session->set_userdata('compteur_'.$date,1);
            $date--;
            $this->session->set_userdata('compteurDate',$date);
          }
        }
        for($m=1;$m<=$this->session->userdata('compteurDate');$m++){
          if(isset($_POST['plusheure_'.$m])){
            $pff = $this->input->post();
            $this->session->set_userdata('lieu',$pff['lieu']);
            $this->session->set_userdata('titre',$pff['titre']);
            $this->session->set_userdata('desc',$pff['desc']);
            $i = $this->session->userdata('compteur_'.$m);
            $date = $this->session->userdata('compteurDate');
            for($p=1;$p<=$date;$p++){
              $this->session->set_userdata('date_'.$p,$pff['date_'.$p]);
              for($v=1;$v<=$this->session->userdata('compteur_'.$p);$v++){
                $this->session->set_userdata('heure_'.$p.$v,$pff['heure_'.$p.$v]);
              }
            }
            $i++;
            $this->session->set_userdata('compteur_'.$m,$i);
          }else if(isset($_POST['moinsheure_'.$m])){
            $i = $this->session->userdata('compteur_'.$m);
            if($i>1){
              $pff = $this->input->post();
              $this->session->set_userdata('lieu',$pff['lieu']);
              $this->session->set_userdata('titre',$pff['titre']);
              $this->session->set_userdata('desc',$pff['desc']);
              $date = $this->session->userdata('compteurDate');
              for($p=1;$p<=$date;$p++){
                $this->session->set_userdata('date_'.$p,$pff['date_'.$p]);
                for($v=1;$v<=$this->session->userdata('compteur_'.$p);$v++){
                  $this->session->set_userdata('heure_'.$p.$v,$pff['heure_'.$p.$v]);
                }
              }
              $this->session->unset_userdata('heure_'.$m.$i);
              $i--;
              $this->session->set_userdata('compteur_'.$m,$i);
            }
          }
        }
        $this->load->view('sondage');
      } else {
        $this->load->model('doodle');
        $this->doodle->creation_sondage();
        redirect('ControlMail/');
      }
 		}
    public function addMail(){
      $this->load->view('Mail');
    }
    public function affSess(){
      print_r($this->session->userdata());
    }
	}
?>
