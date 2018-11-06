<!DOCTYPE html>                                                                                    
<html lang="fr">
  <head>
    <meta charset="UTF-8" />
    <link rel="stylesheet" type="text/css" href="<?php echo css_url('style')?>">
    <link rel="stylesheet" type="text/css" href="<?php echo css_url('bootstrap.min')?>">

    <title>SwimmingPoll</title>
  </head>
  <body style="height:100vh;">
    <div class="container h-100">
      <header>
        <br>
        <div class="row">
          <div class="col-md-4">
            <a class="lien" href="/~quernec/PHP/Project_php/index.php/Control/connexion">Se connecter</a>
          </div>
          <div class="col-md-2 offset-6">
            <a class="lien" href="/~quernec/PHP/Project_php/index.php/Fichier">Créer un compte</a>
          </div>
        </div>
      </header>
      <div class="row" style="margin-top:15%;">
        <div class="col-lg-12">
          <img class="mx-auto d-lg-block" alt="" src="<?php echo img_url('presentation.png');?>"/>
        </div>
        <div class="col-lg-8 offset-2 text-center">
          <br>
          <h4>Site de partage de sondages entre particuliers</h4>
        </div> 
      </div>
    </div>
    <footer class="footb">
    <div class="row w-100">
      <div class="col-md-3 offset-1 text-white">
        Majdi BAAZIZ & Thomas QUERNEC
      </div>
      <div class="col-md-2 offset-1 text-white">
        Réalisé en PHP
      </div>
      <div class="col-md-2 offset-3 text-white">
        IUT de Fontainebleau
      </div>
    </div>
  </footer>
  </body>
  
</html>