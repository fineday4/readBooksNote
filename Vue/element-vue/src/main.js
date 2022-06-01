// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue';
import App from './App';
import VueRouter from 'vue-router';
import ElementUI from 'element-ui';
import router from './router';
import 'element-ui/lib/theme-chalk/index.css';
import axios from 'axios';
import Vuex from 'vuex';
import store from './store' 

Vue.config.productionTip = false

Vue.use(VueRouter);
Vue.use(ElementUI);
Vue.use(Vuex);

Vue.prototype.axios = axios;


router.beforeEach((to, from, next)=>{
  let isLogin = sessionStorage.getItem('isLogin');
  if(to.path == '/logout') {
    console.log('to.path: ', to.path)
    sessionStorage.clear();
    next({path:'/login'});
  } else if (to.path == 'login') {
    if(isLogin != null) {
      next({path:'/main'});
    }
  }
  next();
});

/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  store,
  render: h => h(App)
})
