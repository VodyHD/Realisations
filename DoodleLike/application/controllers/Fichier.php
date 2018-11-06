<?php
	class Fichier extends CI_Controller {
		public function index() {
	  	$this->load->library('form_validation');
      $this->form_validation->set_rules('login','Login','required');
      $this->form_validation->set_rules('mdp','MotDePasse','required');
      $this->form_validation->set_rules('mdp1','MotDePasseV','required|matches[mdp]');
      $this->form_validation->set_rules('mail','mail','required');
      $this->form_validation->set_rules('nom','Nom','required');
      $this->form_validation->set_rules('prenom','Prenom','required');
      if($this->form_validation->run() == FALSE){
        $this->load->view('creation');
      }else{
        $this->load->model('doodle');
        $test = $this->doodle->creation();
        if($test>0){
          $this->load->view('First');
        }else{
          echo "<p>bien .......</p>";
        }
      }
	  	
 		}
	}
?>
