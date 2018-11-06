<!DOCTYPE html>                                                                                    
<html lang="fr">
  <head>
    <meta charset="UTF-8" />
    <link rel="stylesheet" type="text/css" href="<?php echo css_url('style')?>">
    <link rel="stylesheet" type="text/css" href="<?php echo css_url('bootstrap.min')?>">
    <title>Login</title>
  </head>
  <body>
    <div class="h-100">
      <header>
        <br>
        <div class="row w-100">
          <div class="col-md-4">
            <a class="lien" href="/~quernec/PHP/Project_php"><img class="mx-auto d-lg-block" alt="" src="<?php echo img_url('presentation200.png');?>"/></a>
          </div>
          <div class="col-md-4 offset-4">
            <br>
            Ou alors <a class="lien" href="/~quernec/PHP/Project_php/index.php/Fichier">Créer un compte</a>
          </div>
        </div>
      </header>
      <div class="ml-auto mr-auto" style="margin-top: 10%; width: 35%;">
        <form method="POST">
              <div class="text-center" style="margin-bottom: 10%;">
                  <h3>Connexion</h3>
              </div>
              <div class="form-group row">
                <label class="col-md-4 col-form-label">Login : </label>
                <div class="col-md-8">
                  <input type="text" class="form-control" name="login"/>
                </div>
              </div>
              <div class="form-group row">
                <label class="col-md-4 col-form-label">Mot de passe : </label>
                <div class="col-md-8">
                  <input type="password" class="form-control" name="passwd"/>
                </div>
              </div>
              <div class="form-group row">
                <div class="ml-auto mr-auto">
                  <input type="submit" class="btn btn-primary" value="S'authentifier"/>
                </div>
              </div>
          </form>
      </div>
    </div>
    <footer class="footb">
    <div class="row w-100">
      <div class="col-md-3 offset-1" style="color:white;">
        Majdi BAAZIZ & Thomas QUERNEC
      </div>
      <div class="col-md-2 offset-1" style="color:white;">
        Réalisé en PHP
      </div>
      <div class="col-md-2 offset-3" style="color:white;">
        IUT de Fontainebleau
      </div>
    </div>
  </footer>
  </body>
  
</html>