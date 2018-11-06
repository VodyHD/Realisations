<?php
	class Control extends CI_Controller {
	public function __construct(){
		parent::__construct();
		$this->load->library('table');
 		$this->load->library('session');
		$this->load->helper(array('form', 'url'));
	}
	public function index() {
		if(isset($_GET['cle'])){
			$this->load->model('doodle');
			$x = $this->doodle->rechercheStatus($_GET['cle']);
			$p = $x[0];
			if($p['status']=="true" && count($p)>0)
        	{
        		$this->session->set_userdata('cleparticipant',$_GET['cle']);
        		redirect('/ControlParticip/');
        	}else{
        		redirect('.');
        	}
    	}else{
			if(!isset($this->session->user)){
	    		$this->session->set_userdata('compteurDate',1);
	    		$this->session->set_userdata('compteur_1',1);
	    		$this->session->set_userdata('compteurMail',1);
				$this->load->view('First');
			}else{
				$this->session->unset_userdata('lieu');
				$this->session->unset_userdata('titre');
				$this->session->unset_userdata('desc');
				for($i=1;$i<=$this->session->userdata('compteurDate');$i++){
					$this->session->unset_userdata('date_'.$i);
					for($j=1;$j<=$this->session->userdata('compteur_'.$i);$j++){
						$this->session->unset_userdata('heure_'.$i.$j);
					}
					$this->session->unset_userdata('compteur_'.$i);
				}
				for($j=1;$j<=$this->session->userdata('compteurMail');$j++){
					$this->session->unset_userdata('inputmail_'.$j);
				}
				$this->session->set_userdata('compteurDate',1);
				$this->session->set_userdata('compteur_1',1);
				$this->session->set_userdata('compteurMail',1);
				$this->load->model('doodle');
				$val = $this->doodle->getMySondage();
				if(isset($val[0])){
					$vall = $val[0];
					$dates = $this->doodle->getDate();
					$jour = $this->doodle->getJour();
					$this->load->view('mesSondages',array('sondages'=>$val,
														  'dates'=>$dates,
														  'jours'=>$jour));	
				}else{
					$this->load->view('mesSondages');
				}
			}
		}
	}
    public function connexion(){
	    $this->load->library('form_validation');
	    $this->form_validation->set_rules('login','Login','required');
	    $this->form_validation->set_rules('passwd','MotDePasse','required');
	    if ($this->form_validation->run() == FALSE)
	    {
	        $this->load->view('Main');
	    }
	    else
	    {
	        $this->load->model('doodle');
	        $test = $this->doodle->connexion();
	        $tes = $test[0];
			if(isset($test)){
				$this->session->user = $this->doodle->getInfo();
				if (password_verify($test[1],$tes['passwd'])) {
					$this->load->model('doodle');
					$val = $this->doodle->getMySondage();
					if(isset($val)){
						$dates = $this->doodle->getDate();
						$jour = $this->doodle->getJour();
						$this->load->view('mesSondages',array('sondages'=>$val,
															  'dates'=>$dates,
															  'jours'=>$jour));	
					}else{
						$this->load->view('mesSondages');
					}	
				} else {
					echo "<p>code faux</p>";
					$data = array('login' => $tes['login']);
					$this->load->view('Main',$data);
				}
			} 
			else {
			/* $data = array('login' => $conn['login']);*/
				echo "<p>aucun login ne correspond</p>";
			/*$this->load->view('Main',$data);*/
			}
		}
	}
	public function changeStatus($cle){
		$this->load->model('doodle');
		$this->doodle->alterStatus($cle);
		redirect('/Control');
	}
	public function deconnexion(){
    	$this->session->sess_destroy();     	
    	redirect('Control/');
	}
	/*
	//A revoir
	public function affichage_utilisateur(){
		$this->load->model('doodle');
		$this->doodle->affichage_utilisateur();
	}*/
}
?>
