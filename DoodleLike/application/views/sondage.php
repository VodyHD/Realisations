<!DOCTYPE html>
<html lang="fr">
  <head>
    <meta charset="UTF-8"/>
    <link rel="stylesheet" type="text/css" href="<?php echo css_url('style')?>"/>
    <link rel="stylesheet" type="text/css" href="<?php echo css_url('bootstrap.min')?>"/>
    <title>Créer un sondage</title>
  </head>
    <body>
      <header>
      <br>
      <div class="row w-100">
        <div class="col-md-4">
          <a class="lien" href="/~quernec/PHP/Project_php/"><img class="mx-auto d-lg-block" alt="" src="<?php echo img_url('presentation200.png');?>"/></a>
        </div>
        <div class="col-md-4 offset-4">
          <a class="lien" href="/~quernec/PHP/Project_php/">Mes sondages</a>
          <b style="color:#A6E6FA;">&nbsp;&nbsp;|&nbsp;&nbsp;</b>
          <a class="lien" href="/~quernec/PHP/Project_php/index.php/Control/deconnexion">Deconnexion</a>
        </div>
      </div>
    </header>
        <div class="h-100 ml-auto mr-auto" style="width:35%;margin-top: 2%;">
        <form class="h-100" method="POST">
                <div class="ml-auto mr-auto text-center" style="margin-bottom: 10%;">
                  <h3>Création du sondage</h3><br>
                  <div class="form-group row">
                      <label class="col-md-3 col-form-label">Titre :</label>
                      <div class="col-md-9">
                          <input type="text" class="form-control"  value="<?php echo $this->session->userdata('titre')?>" name="titre" required/><br>
                      </div>
                  </div>
                  <div class="form-group row">
                      <label class="col-md-3 col-form-label">Lieu :</label>
                      <div class="col-md-9">
                        <input type="text" class="form-control" name="lieu" value="<?php echo $this->session->userdata('lieu')?>"/><br>
                      </div>
                </div>
                <div class="form-group row">
                    <label class="col-md-3 col-form-label">Description : </label>
                    <div class="col-md-9">
                        <TEXTAREA name="desc" class="form-control" style="resize:vertical;max-height: 200px;min-height: 100px;" rows=2 cols=40><?php echo $this->session->userdata('desc')?></TEXTAREA>
                   </div>
                </div>
                <?php
                for($m=1;$m<=$this->session->userdata('compteurDate');$m++){?>
                  <div class="dessindate">
                    <h2><?php echo "Date ".$m." :"?></h2>
                    <div class="form-group row">
                      <div class="col-md-2">
                        <label class="col-form-label">Jour :</label>
                      </div>
                      <div class="col-md-4">
                        <input type="date" name="<?php echo "date_".$m ?>" value ="<?php echo "".$this->session->userdata('date_'.$m) ?>" class="form-control"/>
                      </div>
                      <div class="col-md-4 offset-2">
                         <input type="submit" name="<?php echo "plusheure_".$m?>" value="    " style="<?php echo "background:url(".img_url('+.png').") no-repeat;"?>" />
                         <label class="col-form-label">+ Heure -</label>
                         <input type='submit' name="<?php echo "moinsheure_".$m?>" value="    " style="<?php echo "background:url(".img_url('-.png').") no-repeat;"?>"/>
                      </div>
                    </div>
                    <?php for($p=1;$p<=$this->session->userdata('compteur_'.$m);$p++){?>
                      <div class="form-group row">
                        <div class="col-md-2">
                          <label class="col-form-label"><?php echo "Heure ".$p ?></label>
                        </div>
                        <div class="col-md-4">
                          <input type="time" name="<?php echo "heure_".$m.$p ?>" value ="<?php echo "".$this->session->userdata('heure_'.$m.$p) ?>" class="form-control"/>
                        </div>
                      </div>
                    <?php } ?>
                  </div>
                <?php } ?>  
                <div class="form-group row">
                    <div class="ml-auto mr-auto">
                      <br>
                      <input type="submit" name="plusjour" class="btn btn-primary" value="Ajouter une date" />
                      <input type="submit" name="moinsjour" class="btn btn-primary" value="Supprimer une date" />
                      <br><br>
                      <input type="submit" name="envoi" class="btn btn-primary" value="Créer"/>
                    </div>
                </div>
              </div>
        </form>
        </div>
  </body>
</html>

